#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
const int M = 1e6 + 3e5;
struct edge {
	int u, v, w;
} a[M], b[M];
int n, m, k, l, c[20], d[20][10010], fa[10020], v[20];
llong ans = 1LL << 60LL; 
bool cmp(const edge &x, const edge &y) {
	return x.w < y.w;
}
int gf(int x) {
	if (fa[x] == x) return x;
	return fa[x] = gf(fa[x]);
}
llong kr() {
	llong ans = 0;
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	sort(b + 1, b + l + 1, cmp);
	for (int i = 1; i <= l; i++) {
		int fu = gf(b[i].u), fv = gf(b[i].v);
		if (fu != fv) {
			ans += b[i].w;
			fa[fu] = fv;
		}
	} 
	return ans;
}
void dfs(int i, llong s) {
	if (i == k + 1) {
		for (int j = 1; j <= m; j++)
			b[j] = a[j];
		l = m;
		for (int j = 1; j <= k; j++)
			if (v[j]) {
				for (int o = 1; o <= n; o++) {
					b[++l].u = j + n;
					b[l].v = o;
					b[l].w = d[j][o];
				}
			}
		ans = min(ans, kr() + s);
		return;
	} 
	v[i] = 0;
	dfs(i + 1, s);
	v[i] = 1;
	dfs(i + 1, s + c[i]);
} 

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &d[i][j]);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
} 
