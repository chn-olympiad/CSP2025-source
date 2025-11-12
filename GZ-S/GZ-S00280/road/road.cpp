// GZ-S00280 贵阳市第一实验中学 林钰涵
#include <bits/stdc++.h>
using namespace std;

int n, m, k, fa[10005], c[15], cw[15][10005];
long long ans = 0x3f3f3f3f3f3f3f3f;
array<int, 3> E[1000005], e[1100005];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[i] = {w, u, v};
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &cw[i][j]);
		}
	}
	for (int S = 0; S < 1 << k; S++) {
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		long long res = 0;
		for (int i = 1; i <= m; i++) {
			e[i] = E[i];
		}
		int en = m;
		for (int i = 0; i < k; i++) {
			if (S >> i & 1) {
				res += c[i + 1];
				for (int j = 1; j <= n; j++) {
					e[++en] = {cw[i + 1][j], i + n + 1, j};
				}
			}
		}
		sort(e + 1, e + en + 1);
		for (int i = 1; i <= en; i++) {
			int w = e[i][0], u = e[i][1], v = e[i][2];
			u = find(u), v = find(v);
			if (u != v) {
				res += w;
				fa[u] = v;
			}
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	return 0;
}
