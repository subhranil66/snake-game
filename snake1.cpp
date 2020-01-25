#include <iostream>
#include <conio.h>
#include <windows.h>
#include<stdlib.h>
#include <dos.h>
#include <time.h>
using namespace std;

int gameOver;
const int width = 20;
const int height = 20;
int x,y,fruitX,fruitY,score,flag;
int tailX[100],tailY[100];
int nTail=0;

void Setup()
{
	gameOver = 0;
	//dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	for(int i=0;i<width+2;i++)
	cout<<"#";
	cout<<endl;
	
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
			cout<<"#";
			if(i==y && j==x)
			cout<<"O";
			else if(i==fruitY && j==fruitX)
			cout<<"F";
			else
			{
				int ch=0;
				for(int k=0;k<nTail;k++)
				{
					if(tailX[k]==j && tailY[k]==i)
					{
						cout<<"o";
						ch=1;
					}
				}
				if(ch==0)
				cout<<" ";
			}
			
			
			if(j==width-1)
			cout<<"#";
		}
		cout<<endl;
	}

for(int i=0;i<width+2;i++)
cout<<"#";
cout<<endl;
cout<<"Score:"<<score<<endl;
}
void Input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
            flag=1;
            break;
            case 'd':
            flag=2;
            break;
            case 'w':
            flag=3;
            break;
            case 's':
            flag=4;
            break;
            case 'x':
            gameOver=1;
            break;
        }
    }
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X,prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i=1;i<nTail;i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch(flag)
    {
        case 1:
        x--;
        break;
        case 2:
        x++;
        break;
        case 3:
        y--;
        break;
        case 4:
        y++;
        break;
        default:
        break;
    }
	if(x>width || x<0 || y>height || y<0)
	gameOver = 1;
	//if(x>=width) x=0; else if(x<0) x=width-1;
	//if(y>=height) y=0; else if(y<0) y=height-1;
	
	for(int i=0;i<nTail;i++)
	if(tailX[i]==x && tailY[i]==y)
	gameOver = 1;
	
	if(x==fruitX && y==fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
int main()
{
	Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10);//sleep(10)
	}
	return 0;
}
