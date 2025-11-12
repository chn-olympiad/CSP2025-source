#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5010000;

struct edge {
	int u, v, w, g;
}e[N];
int n, m, k, fa[N], c[N], a[10][N];
bool vis[N];
ll ans;

bool operator < (const edge &a, const edge &b) {
	return a.w < b.w;
}

int find(int u) {
	if (u == fa[u]) return u;
	return fa[u] = find(fa[u]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	if (n <= 1000) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				for (int l = 1; l <= k; l++) {
					e[++m] = {i, j, a[l][i] + a[l][j], l};
				}
	}
	sort(e + 1, e + m + 1);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue;
		ans += e[i].w;
		fa[u] = v;
		vis[e[i].g] = true;
		if (++cnt == n - 1) break;
	}
	for (int i = 1; i <= k; i++) if (vis[i]) ans += c[i];
	printf("%lld\n", ans);
	return 0;
}