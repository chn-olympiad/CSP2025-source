#include <bits/stdc++.h>
using namespace std;
int fa[100001], c[11], w[11][10001], n, m, k;
struct node {
	int u, v, w;
}a[2000001], b[2000001];
bool cmp(node x, node y) {
	return x.w < y.w;
}
int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	}
	bool flag = 1;
	for(int i = 1; i <= k; i ++) {
		scanf("%d", &c[i]); if(c[i] > 0) flag = 0;
		for(int j = 1; j <= n; j ++) scanf("%d", &w[i][j]);
	}
	if(k == 0) {
		sort(a + 1, a + m + 1, cmp);
		for(int i = 1; i <= n; i ++) fa[i] = i;
		int res = 0;
		long long ans;
		for(int i = 1; i <= m; i ++) {
			if(find(a[i].u) != find(a[i].v)) {
				fa[find(a[i].u)] = find(a[i].v);
				ans += a[i].w; res ++;
			}
			if(res == n - 1) break;
		}
		printf("%lld", ans);
	}
	else if(flag) {
		for(int i = 1; i <= n; i ++) fa[i] = i;
		int res = 0;
		long long ans = 0;
		for(int i = 1; i <= m; i ++) {
			if(find(a[i].u) != find(a[i].v)) {
				fa[find(a[i].u)] = find(a[i].v);
				ans += a[i].w; res ++;
			}
			if(res == n - 1) break;
		}
		for(int i = 1; i <= k; i ++) {
			for(int j = 1; j <= n; j ++) {
				a[++ m] = {n + i, j, w[i][j]};
			}
		}
		int res2 = 0;
		long long num = 0;
		sort(a + 1, a + m + 1, cmp);
		for(int i = 1; i <= n + k; i ++) fa[i] = i;
		for(int i = 1; i <= m; i ++) {
			if(find(a[i].u) != find(a[i].v)) {
				fa[find(a[i].u)] = find(a[i].v);
				num += a[i].w;
				if(a[i].u <= n && a[i].v <= n) res2 ++;
			}
			if(res2 == n - 1) break;
		}
		printf("%lld", min(ans, num));
	}
	else {
		sort(a + 1, a + m + 1, cmp);
		for(int i = 1; i <= n; i ++) fa[i] = i;
		long long ans = 0;
		int res = 0;
		for(int i = 1; i <= m; i ++) {
			if(find(a[i].u) != find(a[i].v)) {
				fa[find(a[i].u)] = find(a[i].v);
				ans += a[i].w; res ++;
			}
			if(res == n - 1) break;
		}
		for(int i = 1; i <= k; i ++) {
			int m2 = m;
			for(int j = 1; j <= m; j ++) b[j] = a[j];
			for(int j = 1; j <= n; j ++) {
				b[++ m2] = {n + i, j, w[i][j]};
			}
			sort(b + 1, b + m2 + 1, cmp);
			int res = 0;
			long long num = 0;
			for(int j = 1; j <= n + k; j ++) fa[j] = j;
			for(int j = 1; j <= m2; j ++) {
				if(find(b[j].u) != find(b[j].v)) {
					num += b[j].w;
					fa[find(b[j].u)] = find(b[j].v);
					if(b[j].u <= n && b[j].v <= n) res ++;
				}
				if(res == n - 1) break;
			}
			if(num + c[i] <= ans) {
				ans = num + c[i];
				m = m2;
				for(int j = 1; j <= m; j ++) a[j] = b[j];
			}
		}
		printf("%lld", ans);
	}
	return 0;
}
