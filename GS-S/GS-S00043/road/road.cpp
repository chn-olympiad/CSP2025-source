#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct Node
{
	int v,w;
};
vector<Node> g[10005];
bool vis[10005],use[10005];
int n,m,k;
int a[10005][10005];
int ans = 2147483640;
bool check()
{
	for (int i = 1;i <= n;i++)
		if (!vis[i])
			return false;
	return true;
}
void dfs(int u,int cost)
{
	if (check())
		ans = min(ans,cost);
	for (int i = 0;i < g[u].size();i++)
	{
		int v = g[u][i].v;
		int w = g[u][i].w;
		if (!vis[v])
		{
			vis[v] = true;
			dfs(v,cost + w);
			vis[v] = false;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(vis,false,sizeof vis);
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for (int i = 0;i < k;i++)
		for (int j = 0;j <= n;j++)
			cin >> a[i][j];
	vis[1] = true;
	dfs(1,0);
	cout << ans;
	return 0;
}
