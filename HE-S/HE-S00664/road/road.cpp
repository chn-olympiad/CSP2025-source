#include <bits/stdc++.h>
using namespace std;
int f[10010][10010];
int a[11][10010];
int c[11];
bool b[10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int l=1;l<=k;l++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				f[i][j]=f[j][i]=min(f[i][j],c[l]+a[l][i]+a[l][j]);
			}
		}
	}
	int ans=0;
	int wei;
	for (int i=1;i<=n;i++)
	{
		int jie=1e9;
		if (!b[i])
		{
			b[i]=1;
			for (int j=1;j<=n;j++)
			{
				jie=min(jie,f[i][j]);
				wei=j;
			}
			ans+=jie;
			//i=wei;
			b[wei]=1;
		}
	}
	cout<<ans;
	return 0;
}
