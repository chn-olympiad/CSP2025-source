#include<bits/stdc++.h>

const int N = 1e4 + 100, M = 1e6 + 7, K = 10 + 7, C = 1024 + 7;
const long long inf = 1e18;

int n, m, k, c[K];
long long ans;
struct Edge {
	int u, v, w;
} e[M], p[C][N], h[K][N], r[N * 2];
int pcnt[C], rcnt;

int f[N], d[N];
int init() {
	for (int i = 1; i <= n + k; ++i)
		f[i] = i, d[i] = 1;
}
int find(int u) {
	if (f[u] == u)
		return u;
	f[u] = find(f[u]);
	return f[u];
}
bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v)
		return false;
	if (d[u] < d[v])
		f[u] = v;
	else
		f[v] = u, d[u] = std::max(d[u], d[v] + 1);
	return true;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	std::sort(e + 1, e + m + 1, [](const Edge& a, const Edge& b) {
		return a.w < b.w;
	});
	init(), ans = 0;
	for (int i = 1; i <= m; ++i)
		if (merge(e[i].u, e[i].v))
			p[0][++pcnt[0]] = e[i], ans += e[i].w;
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &c[i]);
		for (int j = 1, a; j <= n; ++j)
			scanf("%d", &a), h[i][j].u = n + i, h[i][j].v = j, h[i][j].w = a;
		std::sort(h[i] + 1, h[i] + n + 1, [](const Edge& a, const Edge& b) {
			return a.w < b.w;
		});
	}
	for (int i = 1; i < (1 << k); ++i) {
		int u = (i & -i), v = i ^ u;
		for (int j = 0; j < k; ++j)
			if (u & (1 << j)) {
				u = j + 1;
				break;
			}
		rcnt = 0;
		int pc = 1, hc = 1;
		while (hc <= n && pc <= pcnt[v]) {
			if (h[u][hc].w < p[v][pc].w)
				r[++rcnt] = h[u][hc], ++hc;
			else
				r[++rcnt] = p[v][pc], ++pc;
		}
		while (hc <= n)
			r[++rcnt] = h[u][hc], ++hc;
		while (pc <= n)
			r[++rcnt] = h[u][pc], ++pc;
		init();
		long long res = 0;
		for (int j = 1; j <= rcnt; ++j)
			if (merge(r[j].u, r[j].v))
				p[i][++pcnt[i]] = r[j], res += r[j].w;
		for (int j = 0; j < k; ++j)
			if (i & (1 << j))
				res += c[j + 1];
		ans = std::min(ans, res);
	}
	printf("%lld", ans);
	return 0;
}
