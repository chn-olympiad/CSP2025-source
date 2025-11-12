#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	if(k==0)
	{
		int a[n+5][n+5],u,v,w,ans=0,f[n+5],vis[n+5];
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			a[u][v]=a[v][w]=w;
		}
		for(int i=1;i<=n;i++) f[i]=9e18,vis[i]=0;
		f[1]=0;
		for(int i=1;i<=n;i++)
		{
			long long minx=9e18,mini=1;
			for(int j=1;j<=n;j++)
			{
				if(!vis[j]&&f[j]<minx) mini=j,minx=f[j];
			}
			ans+=minx;vis[mini]=1;
			for(int j=1;j<=n;j++) f[j]=min(f[j],a[mini][j]);
		}
		cout<<ans;return 0;
	}
	return 0;
}
