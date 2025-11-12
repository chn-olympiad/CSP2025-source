//GZ-S00131 贵阳市华师一学校 孙宇宸
#include <bits/stdc++.h>
using namespace std;

namespace skywave {
	using ll = long long;
	using pii = pair<int, int>;

	constexpr int N = 10000 + 100, M = 1000000 + 100, K = 10 + 2;

	array<int, 3> ed[M], a[K][N], res[M + M], hero[M + M];
	vector<pii> adj[N];
	int fa[N], sz[N], c[K];

	int ff(int u) {
		return u == fa[u] ? u : fa[u] = ff(fa[u]);
	}

	void main() {
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);

		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= m; ++i) {
			cin >> ed[i][0] >> ed[i][1] >> ed[i][2];
//			adj[ed[i][0]].emplace_back(ed[i][1], ed[i][2]);
//			adj[ed[i][1]].emplace_back(ed[i][0], ed[i][2]);
		}

		auto cmp = [](const auto &x, const auto &y) {
			return x[2] < y[2];
		};

		sort(ed + 1, ed + m + 1, cmp);

		bool A = true;
		for (int i = 0; i < k; ++i) {
			cin >> c[i];
			A &= c[i] == 0;
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j][2];
//				adj[n + i + 1].emplace_back(j, ed[i][2]);
//				adj[j].emplace_back(n + i + 1, ed[i][2]);
				a[i][j][0] = n + i + 1;
				a[i][j][1] = j;
			}
			sort(a[i] + 1, a[i] + n + 1, cmp);
		}
//		if (A) {
//			for (int i = 1; i <= m; ++i) {
//
//			}
//			return ;
//		}

		auto mg = [](int u, int v) {
			u = ff(u);
			v = ff(v);
			if (u == v) {
				return false;
			}
			if (sz[u] < sz[v]) {
				fa[u] = v;
				sz[v] += sz[u];
			} else {
				fa[v] = u;
				sz[u] += sz[v];
			}
			return true;
		};

		ll ans = 1ll << 62;
		for (int S = A ? ((1 << k) - 1) : 0; S < 1 << k; ++S) {
			for (int i = 1; i <= n + k; ++i) {
				fa[i] = i;
				sz[i] = 1;
			}
			for (int i = 1; i <= m; ++i) {
				res[i] = ed[i];
			}
			int tot = m;
			ll sm = 0;
			for (int i = 0; i < k; ++i) if (S >> i & 1) {
				sm += c[i];
				merge(res + 1, res + tot + 1, a[i] + 1, a[i] + n + 1, hero + 1, cmp);
				tot += n;
				for (int j = 1; j <= tot; ++j) {
					res[j] = hero[j];
				}
			}

			int vis = 0, pc = __builtin_popcount(S), cnt = pc + n;
			for (int i = 1; i <= tot; ++i) {
				int u = res[i][0], v = res[i][1], w = res[i][2];
				if (mg(u, v)) {
					if (v > n) {
						vis |= 1 << (v - n);
					}
					if (u > n) {
						vis |= 1 << (u - n);
					}
					--cnt;
					sm += w;
					if (cnt - pc + __builtin_popcount(vis) == 1) {
						ans = min(ans, sm);
						break;
					}
//					cerr << "??? " << cnt - pc + __builtin_popcount(vis) << ' ' << S << ' ' << u << ' ' << v << ' ' << w << '\n';
				}
			}
		}
		cout << ans << '\n';
	}
}

int main() {
	skywave::main();
	return 0;
}
