#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
const int M=1e6+1;
const int inf=1e9+1;
int n, m, k, ans;
struct edge
{
	int to, cost;
};
vector<edge> adj[N];
int c[N], a[N][N], f[N], dep[N];
struct road
{
	int s, t, w;
}q[M];
bool cmp(road X, road Y)
{
	return X.w<Y.w;
}
void init()
{
	for(int i=1;i<=n;i++)
		f[i]=i, dep[i]=1;
	return;
}
int find(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=find(f[x]);
}
void merge(int x, int y)
{
	int xR=find(x), yR=find(y);
	if(dep[xR]<dep[yR])
		f[xR]=yR, dep[yR]+=dep[xR];
	else
		f[yR]=xR, dep[xR]+=dep[yR];
	return;
}
int count(int x, int y)
{
	int Min=inf, tt;
	for(int i=0;i<k;i++)
		Min=min(Min, c[i]+a[i][x]+a[i][y]);
	for(int i=0;i<adj[x].size();i++)
		if(adj[x][i].to==y)
			tt=adj[x][i].cost;
	return min(Min, tt);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=0, u, v, w;i<m;i++)
	{
		cin>>u>>v>>w;
		adj[u].push_back(edge{v, w});
		adj[v].push_back(edge{u, w});
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	int tem=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			q[tem]=road{i, j, count(i, j)}, tem++;
	sort(q, q+tem, cmp);
	init();
	for(int i=0;i<tem;i++)
	{
		f[q[i].s]=find(q[i].s), f[q[i].t]=find(q[i].t);
		if(f[q[i].s]!=f[q[i].t])
		{
			merge(q[i].s, q[i].t);
			ans+=q[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
