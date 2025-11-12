#include <stdio.h>
#include <stdlib.h>
int n, m, k, fa[10100], siz[10100], c[110], tmp[110], sum, cnt, tot = 1, vis[110];
long long ans, cur;
struct node {
	int u, v, w;
} edge[1100010];
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
int merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return 0;
	if (siz[x] < siz[y]) x ^= y ^= x ^= y;
	siz[x] += siz[y];
	if (siz[x] > tot) tot = siz[x];
	fa[y] = x;
	return 1;
}
int cmp(const void* a, const void* b) { return ((struct node*)a) -> w - ((struct node*)b) -> w; }
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++) scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w), cnt++;
	for (int i = 1; i <= k; i++) {
		scanf("%d", c + i), tmp[i] = c[i], sum += c[i], fa[n + i] = n + i;
		for (int j = 1, w; j <= n; j++) scanf("%d", &w), edge[++cnt].u = n + i, edge[cnt].v = j, edge[cnt].w = w;
	}
	qsort(edge + 1, cnt, sizeof edge[0], cmp);
	if (sum == 0) {
		for (int i = 1; i <= k; i++) c[n + i] = -2;
		for (int i = 1; i <= cnt; i++) {
			int x = edge[i].u, y = edge[i].v, z = edge[i].w;
			if (merge(x, y)) {
				if (x <= n && y <= n) ans += z;
				else {
					if (c[x - n] == -1) ans += z;
					else if (c[x - n] != -2) ans += c[x - n] + z, c[x - n] = -1;
					else c[x - n] = z;
				}
				if (tot == n) break;
			}
		}
		printf("%lld", ans);
	} else {
		ans = 1e18;
		for (int i = 1; i < 1 << k; i++) {
			cur = 0, tot = 0;
			for (int j = 1; j <= k; j++) vis[j] = 0;
			for (int j = 1; j <= n; j++) fa[j] = j, siz[j] = 1;
			for (int j = 1; j <= k; j++) fa[n + j] = n + j, c[j] = tmp[j];
			for (int j = 1; j <= k; j++)
				if (i & (1 << j - 1)) vis[j] = 1;
			for (int j = 1; j <= cnt; j++) {
				int x = edge[j].u, y = edge[j].v, z = edge[j].w;
				if (x > n && !vis[x - n]) continue;
				if (merge(x, y)) {
					if (x <= n && y <= n) cur += z;
					else {
						if (c[x - n] == -1) cur += z;
						else if (c[x - n] != tmp[x - n]) cur += c[x - n] + z, c[x - n] = -1;
						else c[x - n] += z;
					}
					if (tot == n) break;
				}
			}
			if (cur < ans) ans = cur;
		}
		printf("%lld", ans);
	}
	return 0;
}
