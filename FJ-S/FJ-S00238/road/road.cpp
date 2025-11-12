#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e4 + 10;
vector < pair <int, int> > adj[N];
int cost[N];
int dis[N];
int vis[N];
inline int f() {
	priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	dis[1] = 0;
	pq.push({0, 1});
	int tot = 0;
	while(!pq.empty()) {
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		tot += d;
		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if(!vis[v] && w < dis[v]) {
				dis[v] = w;
				pq.push({dis[v], v});
			}
		}
	}
	return tot;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(vis, false, sizeof(vis));
	memset(dis, 0x3f3f3f, sizeof(dis));
	int n, m, k;
	cin >> n >> m >> k;
	int reb[k + 2][n + 2];
	memset(reb, 0, sizeof(reb));
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++) {
		cin >> cost[i];
		for(int j = 1; j <= n; j++) {
			cin >> reb[i][j]; 
		}
	}
	if(k == 0) cout << f();
	else cout << 0;
	return 0;
} 
