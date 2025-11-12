#include<bits/stdc++.h>
using namespace std;
int score[105];
int a[15][15];
int f[15][15];
int k=1,c=1;
int n,m,t;
void dfs(int x,int y)
{
	if(c>n*m)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==t)
				{
					cout<<j<<" "<<i;
				}
			}
		}
		exit(0);
	}
	f[x][y]=1;
	a[x][y]=score[c];	
	c++;
	if(x==1)
	{
		if(f[x+1][y]==0&&x+1<=n&&y>=1&&y<=m)
		{
			dfs(x+1,y);
		}
		if(f[x+1][y]==1&&x<=n&&y+1>=1&&y+1<=m)
		{
			k=!k;
			dfs(x,y+1);
		}
	}
	else if(x==n)
	{
		if(f[x-1][y]==0&&x-1>=1&&y>=1&&y<=m)
		{
			dfs(x-1,y);
		}
		else if(f[x-1][y]==1&&x>=1&&y+1>=1&&y+1<=m)
		{
			k=!k;
			dfs(x,y+1);
		}
	}
	else
	{
		if(k==1&&x+1>=1&&x+1<=n&&y>=1&&y<=m)
		{
			dfs(x+1,y);
		}
		if(k==0&&x-1>=1&&x-1<=n&&y>=1&&y<=m)
		{
			dfs(x-1,y);
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>score[i];
	}
	t=score[1];
	sort(score+1,score+n*m+1,greater<int>());
	if(n==1&&m==1)
	{
		cout<<t;
	}
	else if(n==1)
	{
		for(int i=1;i<=m;i++)
		{
			if(score[i]==t)
			{
				cout<<i<<" "<<1;
				return 0;
			}
		}
	}
	else if(m==1)
	{
		for(int i=1;i<=m;i++)
		{
			if(score[i]==t)
			{
				cout<<1<<" "<<i;
				return 0;
			}
		}
	}
	else
	{
		dfs(1,1);
	}
}
