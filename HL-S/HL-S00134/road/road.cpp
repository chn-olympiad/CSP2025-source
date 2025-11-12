#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
	int u;
	int v;
	long long weight;
} edges[5000006];

int fa[50004], si[50004];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (si[x] < si[y]) swap(x, y);
	fa[y] = x;
	si[x] += si[y];
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int u, v; long long w; scanf("%d%d%lld", &u, &v, &w);
		edges[i] = {u, v, w};
	}
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
			si[i] = 1;
		}
		sort(edges, edges + m, [&](edge a, edge b) {
			return a.weight < b.weight;
		});
		long long tot_cost = 0;
		for (int i = 0; i < m; i++) {
			int u = edges[i].u, v = edges[i].v;
			if (find(u) != find(v)) {
				tot_cost += edges[i].weight;
				uni(u, v);
			}
		}
		printf("%lld\n", tot_cost);
		return 0;
	}
	
	for (int i = 1; i <= k; i++) {
		long long c; scanf("%lld", &c);
//		printf("%lld\n", c);
		for (int j = 1; j <= n; j++) {
			long long a; scanf("%lld", &a);
			if (i == j) continue;
			edges[m++] = {i, j, c + a};
		}
	}
	
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		si[i] = 1;
	}
	sort(edges, edges + m, [&](edge a, edge b) {
		return a.weight < b.weight;
	});
	long long tot_cost = 0;
	for (int i = 0; i < m; i++) {
		int u = edges[i].u, v = edges[i].v;
		if (find(u) != find(v)) {
			tot_cost += edges[i].weight;
			uni(u, v);
//			printf("add %d %d %lld\n", u, v, edges[i].weight);
		}
	}
//	printf("%d, %d\n", n, si[find(1)]);
	printf("%lld\n", tot_cost);
}
