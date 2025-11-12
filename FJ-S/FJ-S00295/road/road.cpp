#include <bits/stdc++.h>

using namespace std;

int read() {
	char c = getchar(); int x = 0, f = 1;
	while (!isdigit(c)) {
		if (c == '-')
			f = -1; c = getchar();
	} while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}

struct edge {
	int u, v, w;
} ed[2000001];

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int n, m, k, fa[10001], mst = 0; long long ans = 0;

int Find(int x) {
	if (x != fa[x])
		return fa[x] = Find(fa[x]);
	return x;
}

void Union(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if (fx != fy)
		fa[fx] = fa[fy];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++)	
		fa[i] = i;
	for (int i = 1, u, v, w; i <= m; i++)
		u = read(), v = read(), w = read(), ed[i] = {u, v, w}, ed[i + m] = {v, u, w};
	for (int i = 1; i <= k; i++) {
		int c = read();
		for (int j = 1; j <= n; j++) 
			int v = read();
	} sort(ed + 1, ed + 2 * m, cmp);
	for (int i = 1; i <= 2 * m && mst < n; i++) {
		int u = ed[i].u, v = ed[i].v, w = ed[i].w;
		if (Find(u) != Find(v))
			Union(u, v), mst++, ans += w;
	} printf("%lld\n", ans);
	return 0;
}
