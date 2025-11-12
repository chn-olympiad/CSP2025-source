#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 2;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	int u[m] = {}, v[m] = {}, w[m] = {};
	
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	
	int a[k][n] = {};
	int c[k] = {};
	
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
		}
	}
	
	for (int i = 1; i <= m; i++) {
		
	}
	
	return 0;
}
