#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct edge{
	int v,w;
};
int n,m,k,u,v,w,c[15],a[15][N],ans;
int dis[N],d[N];
bool vis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
vector<edge> g[M];
void dij(int s)
{
	dis[s]=0;
	q.push({0,s});
	while(q.size()>0)
	{
		int k=q.top().second;
		q.pop();
		if(vis[k]==1)continue;
		vis[k]=1;
		for(int i=0;i<(int)g[k].size();i++)
		{
			int v=g[k][i].v,w=g[k][i].w;
			if(dis[v]>dis[k]+w||dis[v]==-1)
			{
				dis[v]=dis[k]+w;
				d[v]=w;
				q.push({dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)dis[i]=-1;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	dij(1);
	for(int i=1;i<=n;i++)
		ans+=d[i];
	cout<<ans;
	return 0;
}
/*
4 5 0
1 2 2
2 3 2
1 3 5
1 4 6
3 4 4
* 
4 5 0
1 2 2
2 3 2
1 3 5
2 4 5
3 4 1
*/
