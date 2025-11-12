#include<bits/stdc++.h>
using namespace std;
int n,m,g,a[1005],c[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	g=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=0,l=0;
	while(l<n*m)
	{
		y++;
		c[x][y]=a[++l];
		while(x<n and l<n*m) c[++x][y]=a[++l];
		if(l==n*m) break;
		y++;
		c[x][y]=a[++l];
		while(x>1 and l<n*m) c[--x][y]=a[++l];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]==g)
			{
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
}
