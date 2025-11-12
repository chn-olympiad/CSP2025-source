#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long ans;
int fa[100005];
struct node {
	int u, v, w;
} a[100005];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}


bool cmp(node x, node y) {
	return x.w < y.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	while (k--) {
		for (int i = 0; i <= n; i++) {
			int t;
			scanf("%d", &t);
		}
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int x1 = find(a[i].u), x2 = find(a[i].v);
		if (x1 != x2) {
			fa[x1] = x2;
			ans += (long long)a[i].w;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
