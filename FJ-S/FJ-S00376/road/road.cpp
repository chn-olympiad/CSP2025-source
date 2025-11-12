#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 12; // !! 

const int Sz = 1 << 20;
char buf[Sz], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Sz, stdin), p1 == p2) ? 0 : *p1++)

int read() {
	int x = 0; char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
	return x;
}

int n, m, k, f[N << 1], c[K], cnt; ll ans = 2e18;
struct Node { int u, v, w; } edge[M], g[N], e[K][N], G[K * N], tmp[K * N];
inline int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	for (int i = 1; i <= m; ++i) 
		edge[i].u = read(), edge[i].v = read(), edge[i].w = read();
		
	for (int i = 1; i <= k; ++i) {
		c[i] = read();
		for (int j = 1; j <= n; ++j)
			e[i][j].w = read(), e[i][j].v = j, e[i][j].u = n + i;
		std::sort(e[i] + 1, e[i] + 1 + n, [](Node a, Node b){ return a.w < b.w; });
	}
	
	for (int i = 1; i <= n; ++i) f[i] = i; 
	
	std::sort(edge + 1, edge + 1 + m, [](Node a, Node b){ return a.w < b.w; });
	for (int i = 1; i <= m; ++i) 
		if (find(edge[i].u) ^ find(edge[i].v)) g[++cnt] = edge[i], f[find(edge[i].u)] = find(edge[i].v);
	m = cnt;
	
	for (int S = 0; S < 1 << k; ++S) {
		cnt = m; ll res = 0;
		for (int i = 1; i <= m; ++i) G[i] = g[i];
		for (int i = 1; i <= k; ++i) {
			if (S >> i - 1 & 1) {
				res += c[i]; int pos = 1, cnt2 = 0;
				for (int i = 1; i <= cnt; ++i) tmp[i] = G[i];
				for (int t = 1; t <= n; ++t) {
					while (pos <= cnt && tmp[pos].w < e[i][t].w) G[++cnt2] = tmp[pos++];
					G[++cnt2] = e[i][t];
				}
				while (pos <= cnt) G[++cnt2] = tmp[pos++];
				cnt = cnt2;
			}
		}
		for (int i = 1; i <= n + k; ++i) f[i] = i;
		for (int i = 1; i <= cnt; ++i) 
			if (find(G[i].u) ^ find(G[i].v)) f[find(G[i].u)] = find(G[i].v), res += G[i].w;
		ans = std::min(ans, res);
	} printf("%lld", ans); 
	
	return 0;
}
