#include<cstdio>
#include<iostream>
using namespace std;
int score[104];
int snack[12][12];
int n,m,r,c;
int ming;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&score[i]);
		if(i==1)
		{
			ming=score[i];
		}
		for(int j=i;j>1;j++)
		{
			if(score[j]>score[j-1])
			{
				int temp=score[j];
				score[j]=score[j-1];
				score[j-1]=temp;
			}else
			{
				break;
			}
		}
	}
	int Point=1,ansx=0,ansy=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				snack[i][j]=score[Point];
				if(score[Point]==ming)
				{
					ansx=i;
					ansy=j;
				}
				Point++;
			}
		}else
		{
			for(int j=m;j>=1;j--)
			{
				snack[i][j]=score[Point];
				if(score[Point]==ming)
				{
					ansx=i;
					ansy=j; 
				}
				Point++;
			}
		}
	}
	printf("%d %d",ansx,ansy);
	return 0;
}
