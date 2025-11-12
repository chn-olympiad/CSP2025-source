#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e4 + 5;
const int M = 2e6 + 5;
struct Edge {
	int u, v, bl, w;
} e[M];
int n, m, k, fa[N], cnt, c[N], vis[N];
ll ans = 1e18;
inline int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
inline bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
inline int read() {
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	n = read(), cnt = m = read(), k = read();
	for (int i = 1; i <= m; i++) e[i].u = read(), e[i].v = read(), e[i].w = read();
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) {
			e[++cnt].w = read();
			e[cnt].bl = i, e[cnt].u = i + n, e[cnt].v = j;
		}
	}
	sort(e + 1, e + 1 + cnt, cmp);
	vis[0] = 1;
	for (int i = 0; i < (1 << k); i++) {
		ll tmp = 0;
		for (int j = 1; j <= n + k; j++) fa[j] = j;
		for (int j = 1; j <= k; j++) {
			vis[j] = 0;
			if ((i >> (j - 1)) & 1) vis[j] = 1, tmp += c[j];
		}
		if (tmp >= ans) continue ;
		int tot = 0;
		for (int j = 1; j <= cnt && tot < n + __builtin_popcount(i); j++) {
			if (!vis[e[j].bl]) continue;
			int p = find(e[j].u), q = find(e[j].v);
			if (tmp >= ans) break;
			if (p != q) {
				fa[p] = q;
				tmp += e[j].w; 
			}
		}
		if (ans > tmp) ans = tmp;
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
