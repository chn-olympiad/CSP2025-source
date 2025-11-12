#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
long long u,v,w;
long long  f[15][1005],a[1001][1001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,127,sizeof(a));
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v>>w;
		a[u][v]=w; 
	}
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>f[i][j];
			cout<<f[i][j]<<endl;
		}
	for(int h=1;h<=k;++h)
	    for(int i=1;i<=n;++i)
		    for(int j=1;j<=n;++j)
			{
				a[i][j]=min(a[i][j],f[h][i]+f[h][j]);
			}
	for(int h=1;h<=n;++h)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				a[i][j]=min(a[i][j],a[i][h]+a[h][j]);
			}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			ans=ans+a[i][j];
			cout<<ans<<endl; 
		}
	cout<<ans/2;
	return 0;
}
