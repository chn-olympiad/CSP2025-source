#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k, tot, c[N], fa[N << 1];
bool vis[N << 1];
struct Edge {
	int u, v, w;
}e[M * 3];
int Rd() {
	int num = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) num = (num << 1) + (num << 3) + (ch ^ 48), ch = getchar();
	return num; 
}
int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
bool cmp(Edge A, Edge B) {
	return A.w < B.w;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	n = Rd(), m = Rd(), k = Rd();
	for (int i = 1; i <= n; i++) vis[i] = 1;
	for (int i = 1; i <= m; i++) e[++tot] = {Rd(), Rd(), Rd()};
 	for (int i = 1; i <= k; i++) {
 		c[i] = Rd();
 		for (int j = 1; j <= n; j++) e[++tot] = {n + i, j, Rd()};
	}
	sort(e + 1, e + tot + 1, cmp); 
	ll ans = 1e18;
	for (int i = (1 << k) - 1; i >= 0; i--) {
		ll res = 0;
		int t = 0;
		for (int j = 1; j <= k; j++) vis[j + n] = 0;
		for (int j = 1; j <= k; j++)
			if ((i >> (j - 1)) & 1) res += c[j], vis[j + n] = 1, t++;
		if (res > ans) continue;
		for (int j = 1; j <= n + k; j++) fa[j] = j;
		int cnt = 0;
		for (int j = 1; j <= tot; j++) {
			if (cnt == t + n - 1) break;
			int u = e[j].u, v = e[j].v, fu = get(u), fv = get(v);
			if (!vis[u] || !vis[v] || fu == fv) continue;
			fa[fu] = fv, cnt++, res += e[j].w;
			if (res > ans) break;
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}

