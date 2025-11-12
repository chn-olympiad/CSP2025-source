#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
	int u, v, w;
} e[1000005];

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int n, m, k, c[15], a[15][10005], ans;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	}
	
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			int w;
			scanf("%lld", &w);
			a[i][j] = a[j][i] = w;
			ans += w;
		}
	}
	cout << ans;

	return 0;
}
