#include <bits/stdc++.h>

#define BUFFER_SIZE (1 << 17)

char buf[BUFFER_SIZE], *p1, *p2;

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUFFER_SIZE, stdin), p1 == p2) ? EOF : *p1++)

inline int read() {
	register int ret = 0, ch, sign = 0;

	while (ch = getchar(), isspace(ch)) ;
	isdigit(ch) ? (ret = (ch ^ 48)) : (sign = (ch == '-'));
	while (ch = getchar(), isdigit(ch))
		ret = (ret << 3) + (ret << 1) + (ch ^ 48);

	return sign ? -ret : ret;
}

#define min(a, b) ((a) < (b) ? (a) : (b))

#define chkmin(u, v) ((u) = min(u, v)) 

#define MAX_N ((int) 1e4)
#define MAX_M ((int) 1e6)
#define MAX_K (10)

int n, m, k, c[MAX_K];

struct Edge {
	int u, v, w;
	inline bool operator < (const Edge& y) const { return w < y.w; } 
} es[MAX_M + 1], a[1 << MAX_K][MAX_N + MAX_K - 1]; 

#define lowbit(x) ((x) & -(x))

int fa[MAX_N + MAX_K + 1];
int findRoot(int x) { return !fa[x] ? x : (fa[x] = findRoot(fa[x])); }
#define check(u, v) (findRoot(u) == findRoot(v))

long long kruskal(const Edge* l, const Edge* r, Edge* brr, int nl, int nr, int tot) {
	long long ret = 0;

	memset(fa + 1, 0, (n + k) * sizeof(int));
	for (int i = 0, j = 0, cnt = 0; cnt < tot; )
		if (j >= nr || (i < nl && l[i] < r[j])) {
			if (!check(l[i].u, l[i].v)) {
				fa[findRoot(l[i].u)] = l[i].v;
				ret += (brr[cnt++] = l[i]).w;
			} i++;
		} else {
			if (!check(r[j].u, r[j].v)) {
				fa[findRoot(r[j].u)] = r[j].v;
				ret += (brr[cnt++] = r[j]).w;
			} j++;
		}

	return ret;
}

long long ans = 0, ret;

main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) es[i].u = read(), es[i].v = read(), es[i].w = read();

	std::sort(es + 1, es + m + 1);
	for (int i = 1, cnt = 0; cnt < n - 1; i++)
		if (!check(es[i].u, es[i].v)) {
			fa[findRoot(es[i].u)] = es[i].v;
			ans += (a[0][cnt++] = es[i]).w;
		}

	for (int i = 0; i < k; i++) {
		ret = c[i] = read();
		
		static Edge u[MAX_N];
		for (int j = 1; j <= n; j++) u[j - 1] = { n + i + 1, j, read() };
		std::sort(u, u + n);

		ret += kruskal(a[0], u, a[1 << i], n - 1, n, n);
		chkmin(ans, ret);
	}

	for (int s = 1; s < (1 << k); s++) {
		if (__builtin_popcount(s) <= 1) continue;
		
		ret = kruskal(a[lowbit(s)], a[s ^ lowbit(s)], a[s], n, n + __builtin_popcount(s) - 2, n + __builtin_popcount(s) - 1);
		for (int i = 0; i < k; i++) ret += c[i] * ((s >> i) & 1);
		chkmin(ans, ret);
	}
	
	printf("%lld\n", ans);
	return 0;
}
