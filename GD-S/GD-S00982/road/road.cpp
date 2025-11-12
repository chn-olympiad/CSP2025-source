#include<bits/stdc++.h>
using namespace std;
#define N 10050
int n, m, i, j, k, x, y, q, l, w, f[N], c[N], s[N];
long long ans, zans;
struct B{
	int l, r, s, p;
} d[N*110];
bool cmp(B a, B b) {
	return a.s < b.s;
}
int find(int k) {
	if (f[k] == k) return k;
	return f[k] = find(f[k]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (l=i=1; i<=m; i++, l++) scanf("%d%d%d", &d[l].l, &d[l].r, &d[l].s);
	for (l--, i=0; i<q; i++) {
		scanf("%d", &s[i]);
		for (j=1; j<=n; j++) {
			l++, d[l].l = n+i+1, d[l].r = j, d[l].p = 1<<i;
			scanf("%d", &d[l].s);
		}
	}
	sort(d+1, d+l+1, cmp);
	zans = 2e18;
	for (i=0; i<(1<<q); i++) {
		for (j=1; j<=n+q; j++) f[j] = j, c[j] = 1;
		for (w=n, ans=j=0; j<q; j++) {
			if (i&1<<j) ans += s[j], w++;
		}
		for (j=1; j<=l && c[find(1)]!=w; j++) {
			x = d[j].l, y = d[j].r;
			if ((!d[j].p || (d[j].p&i)) && find(x) != find(y)) {
				if (c[f[x]] < c[f[y]]) c[f[y]] += c[f[x]], f[f[x]] = f[y];
				else c[f[x]] += c[f[y]], f[f[y]] = f[x];
				ans += d[j].s;
			}
		}
		zans = min(zans, ans);
	}
	printf("%lld", zans);
	return 0;
}

