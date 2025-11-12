#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int M = 2e6 + 10;
struct Edge {
	int u, v, w, flag = 0;
}e[M];
int a[20][N], c[20];
int fa[M];

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int find (int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			a[i][j] += c[i];
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			e[n + (i - 1) * n + j].u = n + i;
			e[n + (i - 1) * n + j].v = j;
			e[n + (i - 1) * n + j].w = a[i][j];
		}
	}
	sort(e + 1, e + m + n * k + 1, cmp);
	long long tot = 0;
	for (int i = 1; i <= m + n * k; i++) fa[i] = i;
	for (int i = 1; i <= m + n * k; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int f1 = find(u);
		int f2 = find(v);
		if (f1 != f2) {
			tot += w;
			fa[f2] = f1;
			e[i].flag = 1;
		}
	}
	printf("%d", tot);
	return 0;
} 
