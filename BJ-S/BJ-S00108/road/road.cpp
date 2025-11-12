#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e4, MAXM = 2e6, MAXK = 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, K, u, v, w, nm;
int c[MAXK + 5];
int fa[MAXN + 5], sz[MAXN + 5];
ll ans = INF;
array<int, 3> edge[MAXM + 5];
inline int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
inline void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (sz[x] > sz[y]) swap(x, y);
	fa[x] = y;
	sz[y] += sz[x];
}
ll solve(int k) {
	int vcnt = __builtin_popcount(k);
	ll res = 0;
	for (int i = 1; i <= K; i ++)
		if (k >> (i - 1) & 1)
			res += c[i];
	iota(fa + 1, fa + n + K + 1, 1);
	fill(sz + 1, sz + n + K + 1, 1);
	for (int i = 1, cnt = 0; i <= nm && cnt < n + vcnt - 1; i ++) {
		int u = edge[i][1], v = edge[i][2], w = edge[i][0];
		if (u > n && ! (k >> (u - n - 1) & 1)) continue;
		u = find(u);
		v = find(v);
		if (u == v) continue;
		merge(u, v);
		res += w;
		cnt ++;
	}
	return res;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &u, &v, &w);
		edge[++ nm] = {w, u, v};
	}
	for (int i = 1; i <= K; i ++) {
		scanf("%d", c + i);
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &w);
			edge[++ nm] = {w, n + i, j};
		}
	}
	sort(edge + 1, edge + nm + 1);
	for (int i = 0; i < (1 << K); i ++)
		ans = min(ans, solve(i));
	printf("%lld\n", ans);
	return 0;
}
