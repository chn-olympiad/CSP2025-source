#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 1e4 + 10;

struct Node {
	LL v, w;
};
LL n, m, k, u, v, w, c[N], a[N][N];
vector<Node> G[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	while (m--) {
		scanf("%lld %lld %lld", &u, &v, &w);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	bool A = true;
	for (LL i = 1; i <= k; i++) {
		scanf("%lld", c + i);
		if (c[i]) A = false;
		bool tmp = false;
		for (LL j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			if (!a[i][j]) tmp = true;
		}
		A &= tmp;
	}
	if (A) {
		for (LL i = 1; i <= k; i++) {
			LL x = 0;
			for (LL j = 1; j <= n; j++) {
				if (a[i][j] == 0) x = j;
			}
			for (LL j = 1; j <= n; j++) {
				if (x != j) {
					G[x].push_back({j, a[i][j]});
					G[j].push_back({x, a[i][j]});
				}
			}
		}
		k = 0;
	}
	if (k == 0) {
		// Maybe there is a 最小生成树, but I don't know how to white it. 
	}
	return 0;
}