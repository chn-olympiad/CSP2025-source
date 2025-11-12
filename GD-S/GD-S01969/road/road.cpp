#include <bits/stdc++.h>

#define il inline

using namespace std;

using ll = long long;

using pii = pair<int, int>;

const int N = 8e6;

struct edge_t {
	int u, v;
	ll w;
	bool operator < (const edge_t &rhs) const {
		return w < rhs.w;
	}
} e[N + 5];
int n, m, k, c[N + 5], a[20][N + 5], cnt;

void add(int u, int v, ll w) {
	e[++cnt] = {u, v, w};
}

namespace task1 {

int fa[N + 5];

il int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void body() {
	for (int i = 1; i <= N; i++) fa[i] = i;
	sort(e + 1, e + cnt + 1);
	int tot = 0;
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue;
		fa[u] = v, ans += e[i].w;
		if (++tot == n - 1) break;
	}
	printf("%lld\n", ans);
}

}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	bool f = true;
	for (int i = 1; i <= k; i++)
		if (c[i]) f = false;
	if (!k) return task1::body();
	for (int i = 1; i <= k; i++)
		for (int j = 1; j < n; j++)
			for (int l = j + 1; l <= n; l++)
				add(j, l, (ll)c[i] + a[i][j] + a[i][l]);
	task1::body();
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = 1;
//	scanf("%d", &T);
	while (T--) solve();
	return 0;
}

/*
9 12 0
1 2 10
2 3 12
1 4 15
2 5 7
3 6 9
4 5 8
5 6 10
4 7 20
5 8 17
6 9 42
7 8 19
8 9 40
*/
