#include <bits/stdc++.h>
using namespace std;

#define int long long
#ifndef LOCAL_TEST
#define endl '\n'
#endif

const int MAXN = 2e4 + 5;
int n, m, k, fa[MAXN], c[15], a[15][MAXN];

namespace bruteforce {
	struct _edge {
		int u, v, w;
		bool operator < (const _edge b) const {
			return w < b.w;
		}
	};

	int find(int x) {
		if (fa[x] == x) return x;
		else return fa[x] = find(fa[x]);
	}

	void work() {
		vector<_edge> edg, mst;
		for (int i = 1; i <= m; ++i) {
			int u, v, w; cin >> u >> v >> w;
			edg.push_back({u, v, w});
		}
		for (int i = 0; i < k; ++i) {
			cin >> c[i];
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n + k; ++i)
			fa[i] = i;
		sort(edg.begin(), edg.end());
		int ans = 0, cnt = 0;
		for (auto e:edg) {
			int u = e.u, v = e.v, w = e.w;
			if (find(u) == find(v)) continue;
			fa[find(u)] = find(v);
			mst.push_back({u, v, w});
			ans += w;
			cnt++;
			if (cnt == n - 1) break;
		}
		for (int S = 0; S < (1ll << k); ++S) {
			for (int i = 1; i <= n + k; ++i)
				fa[i] = i;
			int tmp = 0;
			for (int i = 0; i < k; ++i) {
				if (S >> i & 1) tmp += c[i];
			}
			if (tmp > ans) continue;
			vector<_edge> now;
			for (auto e:mst) {
				now.push_back(e);
			}
			for (int i = 0; i < k; ++i) {
				if (!(S >> i & 1)) continue;
				for (int j = 1; j <= n; ++j) {
					now.push_back({n + i + 1, j, a[i][j]});
				}
			}
			sort(now.begin(), now.end());
			cnt = 0;
			for (auto e:now) {
				int u = e.u, v = e.v, w = e.w;
				if (find(u) == find(v)) continue;
				fa[find(u)] = find(v);
				tmp += w;
				if (tmp > ans) break;
				cnt++;
				if (cnt == n + __builtin_popcountll(S) - 1) break;
			}
			ans = min(ans, tmp);
		}
		cout << ans << endl;
	}
}

void work() {
	cin >> n >> m >> k;
	return bruteforce::work();
}

signed main(void) {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	work();
	return 0;
}
