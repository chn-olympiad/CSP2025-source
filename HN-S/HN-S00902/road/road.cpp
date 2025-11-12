#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
struct Node
{
	ll u, v, w;
};
int n, m, k, fa[N], cnt;
ll cost[N], dis[15][N], ans;
int findr(ll x)
{
	return fa[x] == x ? x : fa[x] = findr(fa[x]);
}
bool cmp(const Node nodex, const Node nodey)
{
	return nodex.w < nodey.w;
}
bool vis[15];
vector<Node> e;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= k; i++)
	{
		cin >> cost[i];
		for(int j = 1; j <= n; j++)
		{
			ll w;
			cin >> w;
			dis[i][j] = w;
		}
	}
	sort(e.begin(), e.end(), cmp);
	for(int i = 0; i < m; i++)
	{
		int sx = findr(e[i].u), sy = findr(e[i].v);
		if(sx == sy)
			continue;
		else
		{
			ll mincost = 9e18, mincosti = 0;
			for(int j = 1; j <= k; j++)
			{
				ll temp = cost[j] + dis[j][sx] + dis[j][sy];
				if(vis[j] == true)
					temp -= cost[j];
				if(temp < mincost)
					mincost = temp, mincosti = j;
			}
			if(mincost <= e[i].w)
				ans += mincost, vis[mincosti] = true;
			else
				ans += e[i].w;
			fa[sy] = sx;
			for(int j = 1; j <= k; j++)
				dis[j][sx] = min(dis[j][sx], dis[j][sy]);
			cnt++;
		}
		if(cnt == n - 1)
			break;
	}
	cout << ans << '\n';
	return 0;
}
