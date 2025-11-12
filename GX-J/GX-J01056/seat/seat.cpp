#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int sco[100+10],n,m,fin;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,e=n*m;i<=e;i++)
		scanf("%d",sco+i);
	fin=sco[1];
	sort(sco+1,sco+n*m+1,cmp);
	for(int i=1,row=1,e=n*m;i<=e;row++)
	{
		if(row%2)
		{
			for(int lin=1;lin<=n;lin++,i++)
			{
				if(sco[i]==fin)
				{
					printf("%d %d",row,lin);
					return 0;
				}
			}	
		}		
		else
			for(int lin=n;lin>=1;lin--,i++)
			{
				if(sco[i]==fin)
				{
					printf("%d %d",row,lin);
					return 0;
				}
			}
	}
	return 0;
}
