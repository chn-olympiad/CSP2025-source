#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=0x3f;
int a[1005][1005],c[100005];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=0x3f;
			if(i==j)a[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(a[u][v]>w)
		{
			a[u][v]=w;
			a[v][u]=w;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		int w;
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			if(a[i][j]>w)
			{
				a[i][j]=w;
				a[j][i]=w;
			}
		}
	}
	floyd();
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			int res=0;
			for(int j=1;j<=n;j++)
			{
				res=res+a[i][j];
			}
			ans=min(ans,res);
		}
		cout<<ans;
		return 0;
	}
}
