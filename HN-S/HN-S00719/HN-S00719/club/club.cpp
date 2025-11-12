#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N=100001;

int club(int i=1,int j=1,int n,int t,int sum,int Manyidu[4][N])
{
	fscanf("%d",&t,&n);
	int cnt=0;
	int y=1;
	for(int x=1;x<=t;x++)
	{
		sum=0;
		for(;i<=n;j++)
		{
			for(;j<=3;i++)
			{scanf("%ld",Manyidu[j][i]);
			 cnt=0;
				if(Manyidu[i-z][j-y]!=Manyidu[i][j])
				{	
					if(Manyidu[i][j])
					{
						if(Manyidu[i][j]>Manyidu[i][j+1] and Manyidu[i][j]>Manyidu[i][j+2])
						{
							if(Manyidu[i][j]>Manyidu[i][j+1] and Manyidu[i][j]>Manyidu[i][j-1])
							{
								if(Manyidu[i][j]>Manyidu[i][j-1] and Manyidu[i][j]>Manyidu[i][j-2])
								{
									cnt+=Manyidu[i][j];
								}
							}
						}
					}
					else
					{
						countine;
					}
					for(;i<=n;j++)
					{
						for(;j<=3;i++)
						{
							if(y=3)
							{
								y=0
							}
							y+=1;
							z+=1;
						}
					}
				}
			}
		}
	}
	sum+=cnt;
	return sum; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int a;
	a=club();
	fprintf("%d\n",a);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
