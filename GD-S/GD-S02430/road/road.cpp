#include <bits/stdc++.h>
using namespace std;
//2  road
vector<int> a[1000010];
int n, m, k, c[10010], cj, w[10010], f[10010];
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int U, V, S;
		scanf("%d%d%d", &U, &V, &S);
		a[U].push_back(V);
		a[V].push_back(U);
		w[U] = w[V] = S;
	}
	scanf("%d", &cj);
	for (int i = 1; i <= n; i++) scanf("%d", c[i]);
	for (int i = 1; i <= n; i++) {
		if (!w[i]) continue; 
		for (int j = w[i]; j >= 1; j--) {
			for (auto it : a[i]) f[j] = max(f[j], f[j - 1] + w[it]);
		}
	}
	if (k == 0) {
		int maxn = 1e18;
		for (int i = 1; i <= n; i++) maxn = min(maxn, f[i]);
		printf("%d", maxn);
	}
	
	return 0;
}
