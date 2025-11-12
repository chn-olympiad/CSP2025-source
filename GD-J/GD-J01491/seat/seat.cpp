#include<bits/stdc++.h>
using namespace std;
bool memorization[101][101];
int a[10001];
int n,m,final;
bool in_maze(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void dfs(int x,int y,int cnt)
{
	if (final==cnt)
	{
		printf("%d %d",y,x);
		exit(0);
	}
	memorization[x][y]=1;
	if (in_maze(x+1,y)==1&&memorization[x+1][y]==0)
	{
		dfs(x+1,y,cnt+1);
	}
	else if (in_maze(x-1,y)==1&&memorization[x-1][y]==0)
	{
		dfs(x-1,y,cnt+1);
	}
	else
	{
		dfs(x,y+1,cnt+1);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	t=a[1];
	sort(a+1,a+(n*m)+1,greater<int>());
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==t)
		{
			final=i;
			break;
		}
	}
	memset(memorization,0,sizeof(memorization));
	dfs(1,1,1);
	return 0;
}
