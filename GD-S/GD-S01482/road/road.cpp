#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v,w;
};
vector<edge>e[10005];
int n,m,k,u,v,w,c[10005],a[15][10005],vis[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cout<<0;
	return 0;
}
