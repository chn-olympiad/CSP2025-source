#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 1e4 + 15, M = 1e6 + 7, MM = 2e6 + 7, K = 12;
const ll INF = 2e18;

int c[K], a[K][N];
// int freeCity[K];

struct Edge {
	int u, v, w;
};

bool cmp (Edge A, Edge B) {
	if (A.w == B.w) {
		if (A.u == B.u) return A.v < B.v;
		return A.u < B.u;
	}
	return A.w < B.w;
}

Edge given_edges[M], cur_edges[MM];

struct unionSet {
	int fa[N];

	int findfa(int u) {
		return (fa[u] == u) ? (u) : (fa[u] = findfa(fa[u]));
	}

	void reset(int n) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
} uset;

ll kruskal(int n, int cur_m) {
	uset.reset(n);
	sort(cur_edges + 1, cur_edges + cur_m + 1, cmp);
	ll costs = 0;
	int cnt = 0;
	for (int i = 1; i <= cur_m; i++) {
		if (cnt == n - 1) break; // is a tree
		auto [u, v, w] = cur_edges[i];
		if (u != v && uset.findfa(u) != uset.findfa(v)) {
			costs += w;
			uset.fa[u] = v;
			cnt++;
		}
	}
	return costs;
}

void sub1to4(int n, int m) {
	for (int i = 1; i <= m; i++) {
		cur_edges[i] = given_edges[i];
	}
	ll res = kruskal(n, m);
	printf("%lld\n", res);
	return;
}

void subA(int n, int m, int k) {
	// puts("A");
	int cur_m = m;
	for (int i = 1; i <= m; i++) {
		cur_edges[i] = given_edges[i];
	}
	for (int i = 1; i <= k; i++) {
		int freeCity = -1;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0) {
				freeCity = j;
				break;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (j == freeCity) continue;
			cur_m++;
			cur_edges[cur_m] = {freeCity, j, a[i][j]};
		}
	}
	ll res = kruskal(n, cur_m);
	printf("%lld\n", res);
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	bool is_A = true;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		given_edges[i] = {u, v, w};
	}

	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		if (c[i] != 0) is_A = false;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	// puts("A");
	// printf("%d\n", is_A);

	if (k == 0) {
		sub1to4(n, m);
		return 0;
	}

	if (is_A) {
		subA(n, m, k);
		return 0;
	}

	ll min_costs = INF;

	for (int subset = 0; subset < (1 << k); subset++) {
		ll cur_costs = 0;
		int cur_m = m;
		int towns = 0;
		for (int i = 1; i <= m; i++) {
			cur_edges[i] = given_edges[i];
			// printf("%d: link(%d, %d, %d)\n", i, u, v, w);
		}
		for (int j = 0; j < k; j++) {
			if (subset & (1 << j)) {
				// select "TOWN" (j+1) to upgrade
				int idx = j + 1;
				for (int i = 1; i <= n; i++) {
					cur_m++;
					cur_edges[cur_m] = {n + towns + 1, i, a[idx][i]};
					// printf("%d: link(%d, %d, %d)\n", cur_m, n + towns + 1, i, a[idx][i]);
				}
				towns++;
				cur_costs += c[idx];
				// printf("+= %d\n", c[idx]);
			}
		}

		cur_costs += kruskal(n + towns, cur_m);
		// printf("cur_cost = %lld\n", cur_costs);
		min_costs = min(min_costs, cur_costs);
	}

	printf("%lld\n", min_costs);
	return 0;
}

/*
15:40 start

16:36 16pts..?!
18:25 speA cannot do it
*/