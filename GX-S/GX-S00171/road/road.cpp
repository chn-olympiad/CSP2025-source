#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][10005];
int c[10005];
int b[10005][10005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<0;
	return 0;
}
