#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, u, v, w;
struct xiang {
	int c, a[10005];
} xiangs[15];
struct Edge {
	int u, v, w;
} edge[1000005];
int fa[10005];
int find(int x) {
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
int sz;
bool merge(int x, int y) {
	int fax = find(x), fay = find(y);
	if(fax == fay)
		return false;
	fa[fax] = fay;
	sz--;
	return true;
}
void Kruskal() {
	sort(edge + 1, edge + 1 + m, [](Edge a, Edge b) {
		return a.w < b.w;
	});
	sz = n;
	iota(fa + 1, fa + 1 + n, 1);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (merge(edge[i].u, edge[i].v))
			ans += edge[i].w;
		if(sz == 1)
			break;
	}
	cout << ans;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &u, &v, &w);
		edge[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &xiangs[i].c);
		for (int j = 1; j <= n; j++)
			scanf("%lld", &xiangs[i].a[j]);
	}
	if (k == 0) {
		Kruskal();
	} else {
		int yn = n;
		for (int i = 1; i <= k; i++) {
			n++;
			for (int j = 1; j <= yn; j++) {
				edge[++m] = {n, j, xiangs[i].a[j]};
			}
		}

		//for (int i = 1; i <= m; i++) {
		//	cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl;
		//}
		Kruskal();
	}
	return 0;
}
