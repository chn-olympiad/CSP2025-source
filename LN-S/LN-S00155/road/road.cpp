#include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct Node {
	vector<int> cost;
	vector<bool> fixed;
	int conect;
} a[10001];
struct country {
	int cost;
	vector<int> costs;
	vector<bool> fixed;
} c[11];
long long solve(const int& i) {
	if (i > n) {
		return 0;
	}
	if (a[i].conect >= n - 1) {
		return solve(i + 1);
	}
	long long Min = 1e16;
	
}
int main() {
	freopen("road.in", "r", std::in);
	freopen("road.out", "w", std::out);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		a[i].cost.resize(n + 1);
		a[i].fixed.resize(n + 1);
		for (int j = 1; j <= n; j++) {
			a[i].fixed[j] = false;
		}
		c[i].costs.resize(n + 1);
		c[i].fixed.resize(n + 1);
		for (int j = 1; j <= n; j++) {
			c[i].fixed[j] = false;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u].cost[v] = w;
		a[v].cost[u] = w;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i].cost);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &c[i].costs[j]);
		}
	}
	printf("%lld\n", solve(1));
	return 0;
}
