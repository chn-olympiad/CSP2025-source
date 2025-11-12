#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, j, k) for (register int i = j; i <= k; ++i)
const int N = 1e4 + 15;
int n, m, dis[N], k, cn[N];
vector<pair<int, int>> g[N];
bool vis[N];
long long ans = 1e18;
int prim(int state) {
	set<pair<int, int>> s;
	int sum = 0;
	rep (i, 2, n) {
		vis[i] = 0, dis[i] = 1e18;
	}
	int c = n;
	rep (i, n + 1, n + k) {
		if (state >> (i - n - 1) & 1) c++, sum += cn[i], vis[i] = 0, dis[i] = 1e18;
		else vis[i] = 1, dis[i] = 1e18;
	}
	rep (i, 1, n + k) if (!vis[i]) s.insert({dis[i], i});
	rep (ttt, 1, c) {
		int u = (*s.begin()).second;
		sum += dis[u];
		if (sum > ans) return sum;
		dis[u] = 0;
		s.erase(s.begin());
		for (auto tmp : g[u]) {
			int v = tmp.first, w = tmp.second;
			if (dis[v] > w && !vis[v]) {
				s.erase({dis[v], v});
				dis[v] = w;
				s.insert({dis[v], v});
			}
		}
	}
	return sum;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	rep (i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	rep (u, n + 1, n + k) {
		cin >> cn[u];
		rep (v, 1, n) {
			int w;
			cin >> w;
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
	}
	ans = prim(0);
	rep (i, 1, (1 << k) - 1) {
		ans = min(ans, prim(i));
	}
	cout << ans << '\n';
}
