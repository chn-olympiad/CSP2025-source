#include <bits/stdc++.h>
int fa[20005], size[20005], c[15];
struct rq {int u, v, w, from;} road[2000005];
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int ra, int rb) {
	if (size[ra] < size[rb]) fa[ra] = rb, size[rb] += size[ra];
	else fa[rb] = ra, size[ra] += size[rb];
}
char file[1 << 26], *fp = file;
#define gc() *(fp++)
int read() {
	int tmp = 0;
	char ch;
	while (!isdigit(ch = gc()));
	for (; isdigit(ch); tmp = tmp * 10 + ch - '0', ch = gc());
	return tmp;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	fread(file, 1, 1 << 26, stdin);
	int n, m, k;
	n = read(), m = read(), k = read();
	for (int i = 0; i < m; ++i) road[i].u = read(), road[i].v = read(), road[i].w = read();
	long long ans = LONG_LONG_MAX;
	for (int i = 0; i < k; ++i) {
		c[i] = read();
		for (int j = 1; j <= n; ++j) road[m].w = read(), road[m].u = j, road[m].v = n + 1 + i, road[m++].from = 1 << i; 
	}
	std::sort(road, road + m, [] (const rq &a, const rq &b) -> bool {return a.w < b.w;});
	for (int p = 0; p < (1 << k); ++p) {
		int tmp = n - 1;
		long long now = 0;
		for (int g = p, ind = 0; g; g >>= 1, ++ind) if (g & 1) now += c[ind], ++tmp;
		for (int i = 1; i <= n + k; ++i) fa[i] = i, size[i] = 1;
		for (int i = 0; i < m; ++i) if (road[i].from & p || !road[i].from) {
			int ra = find(road[i].u), rb = find(road[i].v);
			if (ra != rb) {
				merge(ra, rb), now += road[i].w;
				if (!(--tmp)) break;
			}
		}
		if (now < ans) ans = now;
	}
	printf("%lld", ans);
}
