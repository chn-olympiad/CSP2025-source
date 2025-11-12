#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 2;
const int M = 1e4 + 2;
const int K = 1e1 + 2;
const int INF = 0x3f3f3f3f;
int n, m, k, fa[N], head[N], nxt[N << 1], to[N << 1], wt[N << 1], ty[N << 1], tot, c[K], a[K][M], cnt, ans = 0;
struct Edge {
	int u, v, w;
	bool operator < (const Edge &cmp) const {
		return w < cmp.w;
	}
} edg[N];

int Find(int u) {
	return fa[u] == u ? u : fa[u] = Find(fa[u]);
}
void Add(int u, int v, int w, int t) {
	nxt[++tot] = head[u], to[tot] = v, wt[tot] = w, head[u] = tot;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		edg[i] = {u, v, w};
	}
	sort(edg + 1, edg + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = edg[i].u, v = edg[i].v;
		int fu = Find(u), fv = Find(v);
		if (fu != fv) {
			fa[fu] = fv;
			cnt++, ans += edg[i].w;
		}
		if (cnt == n - 1) {
			break;
		}
	}
	printf("%d", ans);
	return 0;
}
