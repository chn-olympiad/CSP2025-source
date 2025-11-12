#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
long long n, m, k, u, v, w, c[N], tot, fa[N], sum[N], cur[N];
struct Edge {
	long long u, v, w;
} edge[N];
void add(long long u, long long v, long long w) {
	edge[++tot].u = u, edge[tot].v = v, edge[tot].w = w;
	edge[++tot].u = v, edge[tot].v = u, edge[tot].w = w;
}
long long cmp(Edge x, Edge y) {
	return x.w < y.w;
}
long long find(long long x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
long long Kruscal() {
	long long ans = 0;
	long long cnt = 0, tmp = n - 1, er = 0;
	for (long long i = 1; i <= tot; i++) {
		long long fx = find(edge[i].u), fy = find(edge[i].v);
		if (edge[i].u > n) {
			sum[edge[i].u]++;
			if (cur[edge[i].u] == 0) cur[edge[i].u] = 1, er++; 
		}
		if (edge[i].v > n) {
			sum[edge[i].v]++;
			if (cur[edge[i].v] == 0) cur[edge[i].v] = 1, er++;
		}
		if (fx != fy) {
			cnt++, fa[fx] = fy, ans += edge[i].w; 
		}
		if (cnt == tmp + er) {
			return ans;
		}
	}
	return 0;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for (long long i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &u, &v, &w), add(u, v, w);
	}
	for (long long i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (long long j = 1; j <= n; j++) {
			scanf("%lld", &w), add(n + i, j, c[i] + w);
		}
	}
	for (long long i = 1; i < N; i++) {
		fa[i] = i;
	}
	sort(edge + 1, edge + tot + 1, cmp);
	long long res = Kruscal(); 
	for (long long i = 1; i <= k; i++) {
		if (sum[i + n] == 0) {
			continue;
		}
		res -= c[i];
	}
	printf("%lld", res);
	return 0;
}
