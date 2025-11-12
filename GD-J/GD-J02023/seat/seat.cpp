#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
int n,m;
int a[110*110],xm;
int vis[110][110],len;
void dfs(int x,int y,int now)
{
	if(now==len+1)
	{
		return;
	}
	if(y%2==1)
	{
		if(x==n)
		{
			vis[x][y+1]=a[now+1];
			dfs(x,y+1,now+1);
			return;
		}
		vis[x+1][y]=a[now+1];
		dfs(x+1,y,now+1);
	}
	else
	{
		if(x==1)
		{
			vis[1][y+1]=a[now+1];
			dfs(1,y+1,now+1);
			return;
		}
		vis[x-1][y]=a[now+1];
		dfs(x-1,y,now+1);
	}
}
bool cmp(int xx,int yy)
{
	return xx>yy;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	len=n*m;
	for(int i=1;i<=len;i++)
	{
		scanf("%d",&a[i]);
	} 
	xm=a[1];
	sort(a+1,a+len+1,cmp);
	vis[1][1]=a[1];
	dfs(1,1,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]==xm)
			{
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
 	return 0;
} 
