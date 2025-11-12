#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[10005][10005],c[15][100005],b[15],v,u,w,sum=0,f[10005][15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>v>>u>>w;
		a[v][u]=w;
		a[u][v]=w;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>b[i];
		for (int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=k;j++)
		{
			f[i][j]=f[i-1][j]+b[i]+c[i][j],f[i][j]+a[i][j];
		}
		
	}
	cout<<f[n][k];
}
