#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k, a[11][10001], tt, nn, anc[10001], c;
int Find(int x) {
	if (anc[x] == x)
		return x;
	return anc[x] = Find(anc[x]);
}
long long ans;
bool vis[10001];
struct Edge {
	int u, v, w;
	bool operator < (const Edge& A) const {
		return w < A.w;
	}
} e[2000001];
void dfs(int x, int fa) {
	vis[x] = true;
	for (int i = 1; i <= tt; i++) {
		if (e[i].u == x && e[i].v != fa)
			dfs(e[i].v, x);
		else if (e[i].v == x && e[i].u != fa)
			dfs(e[i].u, x);
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[i].u = u;
		e[i].v = v;
		e[i].w = w;
	}
//	if (k == 0) {
	if (1) {
		sort(e + 1, e + m + 1);
		for (int i = 1; i <= n; i++)
			anc[i] = i;
		int cnt = 0;
		for (int i = 1; i <= m && cnt < n - 1; i++) {
			int fa = Find(e[i].u), fb = Find(e[i].v);
			if (fa != fb) {
				anc[fa] = fb;
				cnt++;
				ans += e[i].w;
			} 
		}
		printf("%lld", ans);
		return 0;
	}
//	nn = n;
//	tt = m;
//	for (int i = 1; i <= k; i++) {
//		scanf("%d", &a[i][0]);
//		e[++tt].u = 0;
//		e[tt].v = ++nn;
//		e[tt].w = a[i][0];
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &a[i][j]);
//			e[++tt].u = nn;
//			e[tt].v = j;
//			e[tt].w = a[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		e[++tt].u = 0;
//		e[tt].v = i;
//		e[tt].w = 0;
//	}
//	sort(e + 1, e + tt + 1);
////	for (int i = 1; i <= tt; i++)
////		printf("%d ", e[i].w);
////	printf("\n\n");
//	int cnt = 0;
//	for (int i = 1; i <= n; i++)
//		anc[i] = i;
//	for (int i = 1; i <= tt && cnt < n - 1; i++) {
//		int fa = Find(e[i].u), fb = Find(e[i].v);
//		if (fa != fb) {
//			anc[fa] = fb;
//			cnt++;
//			ans += e[i].w;
////			printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
//		}
//	}
//	printf("%lld", ans);
	return 0;
}
