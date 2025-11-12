#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 20;
const int INF = 0x3f3f3f3f;
int n, m, k;
struct C {
	int money;
	int g[N];
}c[K];
long long ans = INF;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
	}
	long long x = 0;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i].money);
		x += c[i].money;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &c[i].g[j]);
			x += c[i].g[j];
		}
		ans = min(ans, x);
	}
	cout << ans;
	return 0;
}
