#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
using namespace std;
const int maxn = 2e6 + 5;
int n, m, k, tot, cur;
struct Edge
{
	ll u, v, w;
	int need;
	bool operator < (const Edge & b) const
	{
		return w < b.w;		
	}	
}edge[maxn];
int c[15];
ll cost[15][10005];
int fa[maxn];
int find(int x)
{
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
map<PII, ll>mp;
int vis[15];
priority_queue<int>q;
int ex[maxn];
int main()
{
	freopen("road.in","r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		if(edge[i].u > edge[i].v) swap(edge[i].u, edge[i].v);
		if(mp[{edge[i].u, edge[i].v}]) 
		{
			if(mp[{edge[i].u, edge[i].v}] < edge[i].w) mp[{edge[i].u, edge[i].v}] = edge[i].w;
		}
		else mp[{edge[i].u, edge[i].v}] = edge[i].w;
	}
	tot = m;	
	ll cnt = 0, ans = 0;
	bool flag = 0;
	vis[0] = 2;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
			cost[i][j] = w; 
			if(cost[i][j]) flag = 1;
		}
		if(!flag)
		{
			cout << 0 << '\n';
			return 0;
		}
		for(int j = 1; j <= n; j++)
		{
			for(int k = j + 1; k <= n; k++)
			{
				if(cost[i][k] + cost[i][j] < mp[{j, k}]) 
				{
					mp[{j, k}] = cost[i][k] + cost[i][j];
					edge[++tot].u = j, edge[tot].v = k, edge[tot].w = mp[{j, k}], edge[i].need = i;
				}
			}
		}
	}
	sort(edge + 1, edge + tot + 1);
	for(int i = 1; i <= tot; i++)
	{
		int res = edge[i].w;
		int u = find(edge[i].u), v = find(edge[i].v);
		if(u == v) continue;
		fa[u] = v; 
		ans += res;
		if(cnt == n - 1) break;
	}
	cout << ans << '\n';
	return 0;
}
