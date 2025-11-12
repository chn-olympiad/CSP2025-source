#include<bits/stdc++.h>
using namespace std;
int d[1000010],c[10010][10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(c[u][v]>w)
		{
			sum-=c[u][v];
			sum+=w;
			c[u][v]=w;
			c[v][u]=w;
		}
		else if(c[u][v]==0)
		{
			c[u][v]=w;
			sum+=w;
			c[v][u]=w;
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			int k;
			cin>>k;
		}
	}
	cout<<sum;
	return 0;
}
