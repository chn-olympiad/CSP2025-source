#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const int N = 1e4 + 2, M = 2e6 + 40, K = 15;

struct Edge {
	int u, v;
	long long w;
} edge[M];

int n, m, k, c[K], d[N];
long long ans, a[K][N];

bool cmp(Edge a, Edge b) {
	return a.w > b.w;
}

void __solve1() {
	// expect AC on 1 2 3 4 5 6 9 10 13 14 17 18
	// but TLE
	scanf("%d %d %d", &n, &m, &k);
	int u = 0, v = 0;
	long long w = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %lld", &u, &v, &w);
		d[u]++, d[v]++;
		edge[i] = {u, v, w};
		ans += w;
	}
	for (int j = 1; j <= k; j++) {
		scanf("%d", &c[j]);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[j][i]);
			if (j != i) {
				d[i]++;
				d[j]++;
				edge[++m] = {j, i, a[j][i]};
				ans += a[j][i];
			}
		}
	}
	sort(edge + 1, edge + m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		if (d[u] > 1 && d[v] > 1 && m - cnt > n - 1)
			ans -= w, d[u]--,  d[v]--, cnt++;  // , printf("taken away %d %d %d\n", u, v, w)
	}
	printf("%lld", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	__solve1();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
