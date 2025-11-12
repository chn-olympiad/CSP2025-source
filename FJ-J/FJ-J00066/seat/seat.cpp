#include<bits/stdc++.h>
using namespace std;
int a[110];
int w[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	scanf("%d%d",&n,&m);
	t=n*m;
	for (int i=1;i<=t;i++)
	{
		scanf("%d",&a[i]);
	}
	int mings=a[1];
	sort(a+1,a+1+t,cmp);
	int s=0;
	for (int i=1;i<=m;i++)
	{
		if (i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				w[i][j]=a[++s];
				if (w[i][j]==mings)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				w[i][j]=a[++s];
				if (w[i][j]==mings)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0; 
}
