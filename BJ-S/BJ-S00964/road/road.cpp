#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 15, M = 1e6 + 5;
int n, m, k, fa[N], c[12], a[12][N], siz[N];
ll ans;
struct edge {int u, v, w;} e[M];
bool cmp(edge x, edge y) {return x.w < y.w;}
int read() {
	int x(0), f(1); char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}
void write(ll x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
ll init() {
	sort(e + 1, e + m + 1, cmp);
	for (register int i(1); i <= n; ++i) fa[i] = i;
	ll ans = 0;
	for (register int i(1), cnt(0); i <= m; ++i) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u != v) fa[u] = v, ans += e[i].w, e[++cnt] = e[i];
	}
	return ans;
}
ll kruskal(int s) {
	for (register int i(1); i <= n + k; ++i) fa[i] = i, siz[i] = 1;
	ll ans = 0;
	for (register int i(1); i <= m; ++i) {
		if (e[i].u > n && !(s & (1 << (e[i].u - n - 1)))) continue;
		if (e[i].v > n && !(s & (1 << (e[i].v - n - 1)))) continue;
		int u = find(e[i].u), v = find(e[i].v);
		if (u != v) {
			ans += e[i].w;
			if (siz[u] > siz[v]) fa[v] = u, siz[u] += siz[v];
			else fa[u] = v, siz[v] += siz[u];
		}
	}
	return ans;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (register int i(1); i <= m; ++i) e[i].u = read(), e[i].v = read(), e[i].w = read();
	ans = init(), m = n - 1;
	for (register int i(1); i <= k; ++i) {
		c[i] = read();
		for (register int j(1); j <= n; ++j) a[i][j] = read(), e[++m] = {n + i, j, a[i][j]};
	}
	sort(e + 1, e + m + 1, cmp);
	for (register int s(1); s < (1 << k); ++s) {
		ll now = 0;
		for (register int i(1); i <= k; ++i) if (s & (1 << (i - 1))) now += c[i];
		ans = min(ans, now + kruskal(s));
	}
	write(ans);
	return 0;
}