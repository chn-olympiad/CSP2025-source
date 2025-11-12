#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int tot,s[210];
int x;
int n,m;
void dfs(int x,int y,int k)
{
	if(y>m)return;
	if((x==1 and k==-1) or (x==n and k==1))
	{
		a[x][y]=s[++tot];
		dfs(x,y+1,-k);
	}
	else
	{
		a[x][y]=s[++tot];
		dfs(x+k,y,k);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	x=s[1];
	sort(s+1,s+1+n*m,
		[](int x,int y)
	{
		return x>y;
	});
	dfs(1,1,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==x)
			{
				cout<<j<<' '<<i;
				exit(0);
			}
		}
	}
}
/*
9:34
秒了前三题
发现不会第四题
前来写俳句

不闹了。

9:46
发现 D 可以推成背包。
想到三次方做法。

10:00
写出三次方做法。

10:10左右
想到正解。

10:25
打完正解。

不知道干什么。
我要上迷惑行为。
*/
