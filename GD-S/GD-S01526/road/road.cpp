#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e4+20;
vector<pair<int, int> > g[maxn];
int c[20][maxn];
int n, m, k;
bool vis[maxn];
int cost[maxn];

int prim() {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<=n; i++) cost[i] = 1e9;
	cost[1] = 0;
	for (int i=0; i<n; i++) {
		int u = 0;
		for (int j=1; j<=n; j++) {
			if (!vis[j] && cost[j] < cost[u]) u = j;
		}
		if (u==0) return -1;
		ans += cost[u];
		vis[u] = 1;
		for (auto p :g[u]) {
			int v = p.first, w = p.second;
			if (!vis[v] && w < cost[v]) {
				cost[v] = w;
			}
		}
	}
	return ans;
}

signed main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i=1; i<=k; i++) {
		int id = 0;
		for (int j=0; j<=n; j++) {
			cin >> c[i][j];
			if (j>=1 && c[i][j]==0) id = j;
		}
		if (c[i][0] == 0) {
			for (int j=1; j<=n; j++) {
				if (j == id) continue;
				g[id].push_back({j, c[i][j]});
				g[j].push_back({id, c[i][j]});
			}
		}
	}
	cout << prim() << '\n';
	
}
