#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],ans,g[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int h=1,l=1;
	g[1][1]=a[1];
	for(int i=2;i<=m*n;i++)
	{
		if(l%2==1)
		{
			if(h+1<=n) h++,g[h][l]=a[i];
			else if(h==n)
			{
				l++,g[h][l]=a[i];
			}
		}
		else
		{
			if(h-1>=1) h--,g[h][l]=a[i];
			else if(h==1) l++,g[h][l]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]==ans)
			{
				printf("%d %d",j,i);
				return 0;
			}
		}
	}	
	return 0;
}
