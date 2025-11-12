#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 2e5 + 5;
struct edge {
	int f, t, ind = 0;
	long long v;
	bool operator < (const edge& other) const {
		return v < other.v;
	}
} e[M];
int fa[N], n, m, k;
long long c[15], vis[15];
int find(int x) {
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
long long doit() {
	int a, b, tot = 0, used = 0;
	long long cnt = 0;
	for (int i = 1; i <= m + k * n; i++) {
		a = find(e[i].f);
		b = find(e[i].t);
		if (a == b) continue;
		if (e[i].ind > 0) {
			if (vis[e[i].ind] == 0) used++;
			vis[e[i].ind]++;
		}
		fa[a] = b;
		cnt += e[i].v;
		tot++;
		if (tot == n + used - 1) return cnt;
	}
	return cnt;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long ans = 0, cnt = 0, v;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n + k; i++) fa[i] = i; 
	for (int i = 1; i <= m; i++) scanf("%d%d%lld", &e[i].f, &e[i].t, &e[i].v);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &v);
			e[m + (i - 1) * n + j].f = n + i;
			e[m + (i - 1) * n + j].t = j;
			e[m + (i - 1) * n + j].v = v + c[i];
			e[m + (i - 1) * n + j].ind = i;
		}
	}
	sort(e + 1, e + m + n * k + 1); 
	ans = doit();
	for (int i = 1; i <= k; i++)
		if (vis[i] > 0) cnt += (vis[i] - 1) * c[i];
	ans -= cnt;
	printf("%lld", ans);
	return 0;
}
