// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Windows.h"
#include<conio.h>
int maps[10][10]=
{
{ 1,4,8,4,4,4,4,4,4,5 },
{ 2,0,2,0,0,0,0,0,0,2 },
{ 2,0,0,0,2,0,0,2,0,2 },
{ 2,4,4,4,11,5,0,2,0,2 },
{ 2,0,0,0,0,2,0,2,0,2 },
{ 2,0,4,4,4,6,0,2,0,2 },
{ 2,0,0,0,0,0,0,2,0,2 },
{ 2,0,1,4,4,4,4,6,0,2 },
{ 2,0,2,12,0,0,0,0,0,2 },
{ 3,4,11,4,4,4,4,4,4,6 },
};
char mapp;
int zx=1, zy=1;
int x, y;
int playerHP=100,emHP=100,em;
int boss = 1,bossHP=500,bossatt;
int win = 0;
int att, adm,round=1;
void battleBoss()
{

	system("cls");
	printf("====BOSS战斗开始====\n");
	Sleep(1000);
	system("cls");
	while (1)
	{
		att = rand() % 100;
		bossatt = rand() % 15;
		bossHP -= att;
		system("cls");
		printf("====第%d回合====\n", round);
		printf("Boss受到伤害%d\n", att);
		printf("玩家生命力%d\tBoss生命力????\n", playerHP );
		printf("--------------\n");
		Sleep(3000);
		if (bossHP <= 0)
		{
			printf("战斗胜利");
			boss = 0;
			Sleep(3000);
			break;
		}
		playerHP -= bossatt;
		printf("玩家受到伤害%d\n", bossatt);
		printf("玩家生命力%d\tBoss生命力????\n", playerHP);
		printf("=============\n");
		Sleep(3000);
		if (playerHP <= 0)
		{
			printf("game over\n");
			printf("=============\n");
			win = 1;
			Sleep(3000);
			break;
		}
		round++;
	}
	round = 1;
}
void battle()
{
	system("cls");
	printf("====战斗开始====\n");
	Sleep(1000);
	system("cls");
	while (1)
	{
		att = rand() % 100;
		adm = rand() % 15;
		emHP -= att;
		system("cls");
		printf("====第%d回合====\n",round);
		printf("敌人受到伤害%d\n", att);
		printf("玩家生命力%d\t敌人生命力%d\n", playerHP, emHP);
		printf("--------------\n");
		Sleep(3000);
		if (emHP <= 0)
		{
			printf("战斗胜利");
			Sleep(3000);
				break;
		}
		playerHP -= adm;
		printf("玩家受到伤害%d\n", adm);
		printf("玩家生命力%d\t敌人生命力%d\n", playerHP, emHP);
		printf("=============\n");
		Sleep(3000);
		if (playerHP <= 0)
		{
			printf("game over\n");
			printf("=============\n");
			win = 1;
			Sleep(3000);
			break;
		}
		round++;
	}
	round = 1;
	emHP = 100;
}
void move()
{
	switch (_getch())
	{
		case '8':
			if ((zy != 1) && (maps[zy-1][zx] == 0))zy--;
			if (playerHP < 100)playerHP++;
			break;
		case '4':
			if ((zx != 1) && (maps[zy][zx -1] == 0) || (maps[zy][zx - 1] == 12))zx--;
			if (playerHP < 100)playerHP++;
			break;
		case '6':
			if ((zx != 8)&&(maps[zy][zx+1]==0))zx++;
			if (playerHP < 100)playerHP++;
			break;
		case '2':
			if ((zy != 8) && (maps[zy + 1][zx] == 0))zy++; 
			if (playerHP < 100)playerHP++;
			break;
	}
}
void map()
{
	system("cls");
	for( y=0;y<10;y++)
	{
		for (int x = 0; x < 10; x++)
		{
			 mapp = maps[y][x];
			
			 if( (mapp == 0))
			{
				 if ((x == zx) && (y == zy))
				 {
					 printf("0");
				 }
				 else
				 {
                   printf(" ");
				 }
				
			}
			if (mapp == 1)
			{
				printf("╔");
			}
			if (mapp == 2)
			{
				printf("║");
			}
			if (mapp == 3)
			{
				printf("╚");
			}
			if (mapp == 4)
			{
				printf("═");
			}
			if (mapp == 5)
			{
				printf("╗");
			}
			if (mapp == 6)
			{
				printf("╝");
			}
			if (mapp == 7)
			{
				printf("╬");
			}
			if (mapp == 8)
			{
				printf("╦");
			}
			if (mapp == 9)
			{
				printf("╠");
			}
			if (mapp == 10)
			{
				printf("╣");
			}
			if (mapp == 11)
			{
				printf("╩");
			}
			if (mapp == 12)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	printf("%d,%d\n", zx, zy);
	printf("%d", playerHP);
}
void game()
{
	
	while (1)
	{
		map();
		move();
		if (win == 0)
		{
			em = rand() % 8;
			if (em == 2)
			{
				battle();
			}
		}
		if ((zx == 3) && (zy == 8))
		{
			
			if (boss == 0)
			{
			win = 1;
			system("cls");
			printf("=============\n");
			printf("game clear\n");
			printf("=============\n");
			Sleep(3000);
			break;
		    }
			if (boss == 1)system("cls"); printf("=============\n"); printf("找出boss打到他\n"); printf("=============\n"); Sleep(2000); zx++;
		}
		if ((zx == 4) && (zy == 4)&&(boss==1))
		{
			battleBoss();
			//boss = 0;
		}
		//if (win == 1) break;
		//Sleep(100);
	}
}

int main()
{
	while (1)
	{
		system("cls");
		printf("游戏开始请按1\n");
		printf("游戏结束请按2\n");
		switch (_getch())
		{
		case'1':
			 zx = 1, zy = 1, playerHP = 100, win = 0;
			 boss = 1, bossHP = 500;
             game();
			 break;
		case'2':
			exit(0);
			break;
		}
		
	}
}
