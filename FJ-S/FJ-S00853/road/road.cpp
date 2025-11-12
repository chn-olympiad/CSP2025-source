#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e4 + 5, M = 2e6 + 5, K = 12;
int c[K], a[K][N], ans = 1e16;

int n, m, k, cnt = 0;
struct edge {
	int u, v, w, xz;
} e[M];

// dsu
int fa[N];
void dsu_init(int n) {
	for (int i = 1; i <= n; i ++)
		fa[i] = i;
	return;
}
int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

bool cmp(edge a, edge b) { return a.w < b.w; }

bool in(int x) {return x <= n;}
int Kruskal(int U) {
	dsu_init(n + k);
	
	int cnt = 0, res = 0;
	
	for (int i = 1; i <= k; i ++)
		if (U & (1 << (i - 1)))
			res += c[i];
	
	for (int i = 1; ; i ++) { // e[i]
		if (e[i].xz != 0 && ((1 << (e[i].xz - 1)) & U) == 0)
			continue;
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		
		if (fu == fv)
			continue;
			
		res += w; // jianzhi
		if (res >= ans)
			return 1e16;
		
		if (in(fu) && in(fv))
			fa[fu] = fv, cnt ++;
		else if (in(fu))
			fa[fv] = fu;
		else
			fa[fu] = fv;
			
		if (cnt == n - 1)
			break;
	}
	return res;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1, u, v, w; i <= m; i ++) {
		scanf("%lld%lld%lld", &u, &v, &w);
		e[++cnt] = (edge){u, v, w, 0};
	}
	for (int i = 1; i <= k; i ++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j ++) {
			scanf("%lld", &a[i][j]);
			e[++cnt] = (edge){n + i, j, a[i][j], i};
		}
	}
	sort(e + 1, e + cnt + 1, cmp);
	
	for (int U = 0; U < (1 << k); U ++) {
		int res = Kruskal(U);
//		printf("D - %d : %d\n", U, res);
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	
	return 0;
}
