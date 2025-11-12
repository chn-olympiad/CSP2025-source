#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n;
int a[5005],b[5005],ans,y[5005][5005];
void dfs(int x,int sum,int maxx,int xuan)
{
	if(x==n-1&&xuan==0)
	{
		return ;
	}
	if(b[n]-b[x-1]+sum<=maxx*2)
	{
		return ;
	}
	if(x>n)
	{
		if(sum>maxx*2&&xuan>=3)
		{
			ans=(ans+1)%Mod;
		}
		return ;
	}
	dfs(x+1,sum+a[x],max(maxx,a[x]),xuan+1);
	dfs(x+1,sum,maxx,xuan);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ts=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			ts++;
		}
		b[i]=b[i-1]+a[i];
	}
	if(ts==n)
	{
		y[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(j==0)
				{
					y[i][j]=1;
					continue;
				}
				y[i][j]=(y[i-1][j]+y[i-1][j-1])%Mod;
			}
		}
		for(int i=3;i<=n;i++)
		{
			ans=(ans+y[n][i])%Mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
