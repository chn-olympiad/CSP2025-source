#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1e4 + 5, M = 1e6 + 5, K = 15, INF = 1e18;

struct To {
	ll v, w;
};

struct Edge {
	ll u, v, w;
};

struct Cmp {
	bool operator () (const Edge &a, const Edge &b) const {
		return a.w < b.w;
	}
};

ll T, n, m, k, ans = INF;
ll a[K][N], u[M], v[M], w[M], c[N], f[N + K], dist[N + K], vis[N + K], b[N + K];
vector<To> g[N + K];
vector<Edge> e;

void Clear() {
	return ;
}

int Find(int x) {
	return f[x] == x ? x : f[x] = Find(f[x]);
}

void Merge(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if (fx == fy) {
		return ;
	}
	f[fx] = fy;
	return ;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if (m <= 1e5) {
		for (int s = 0; s < 1 << k; s++) {
			ll res = 0, cnt = 0;
			e.clear();
			for (int i = 1; i <= m; i++) {
				e.push_back({u[i], v[i], w[i]});
			}
			for (int i = 1; i <= k; i++) {
				if ((s >> i - 1) & 1) {
					cnt++;
					res += c[i];
					for (int j = 1; j <= n; j++) {
						e.push_back({i + n, j, a[i][j]});
					} 
				}
			}
			for (int i = 1; i <= n + k; i++) {
				f[i] = i;
			}
			sort(e.begin(), e.end(), Cmp());
			for (int i = 0, tot = n + cnt; i < e.size() && tot > 1; i++) {
				int u = e[i].u, v = e[i].v, w = e[i].w;
				if (Find(u) != Find(v)) {
					Merge(u, v); 
					res += w;
					tot--;
				}
			}
			ans = min(ans, res);
		}	
	} else if (n <= 1e3 + 5) {
		for (int s = 0; s < 1 << k; s++) {
//			cout << "---------\n";
			ll res = 0, cnt = 0;
			for (int i = 1; i <= n + k; i++) {
				g[i].clear();
			}
			for (int i = 1; i <= m; i++) {
				g[u[i]].push_back({v[i], w[i]});
				g[v[i]].push_back({u[i], w[i]});
//				cout << u[i] << ' ' << v[i] << ' ' << w[i] << '\n';
			}
			for (int i = 1; i <= k; i++) {
				if ((s >> i - 1) & 1) {
//					cout << i << '\n';
					cnt++;
					res += c[i];
					for (int j = 1; j <= n; j++) {
						g[i + n].push_back({j, a[i][j]});
						g[j].push_back({i + n, a[i][j]});
//						cout << i + n << ' ' << j << ' ' << a[i][j] << '\n';
					} 
				}
			}
//			cout << '\n';
			for (int i = 1; i <= n + k; i++) {
				dist[i] = INF;
				vis[i] = 0;
				b[i] = INF;
			}
//			dist[1] = 0;
			b[1] = 0;
			for (int i = 1; i <= n + cnt; i++) {
				int u = 0;
				for (int j = 1; j <= n + k; j++) {
					if ((j <= n || (s >> j - n - 1) & 1) && !vis[j] && (u == 0 || b[u] > b[j])) {
						u = j;
					}
				}
				vis[u] = 1;
				res += b[u];
//				cout << u << ' ' << b[u] << '\n';
				for (To t : g[u]) {
					ll v = t.v, w = t.w;
					if (!vis[v] && b[v] > w) {
//						dist[v] = dist[u] + w;
						b[v] = w;
					}
				}
			}
//			cout << res << '\n';
			ans = min(ans, res);
		}
	} else {
		ans = 0; 
	}
	cout << ans << '\n';
	return 0;
}
/**
*/
