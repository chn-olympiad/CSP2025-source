#include<bits/stdc++.h>
using namespace std;
long long n, m, k, jl[10005][2], a[10005][10005], b[15][10005], c[15], bj[10005], kf[15], ans = 0, syg;
inline void px() {
	for (int i = 1; i <= n; i++)jl[i][0] = min(jl[i][0], a[syg][i]);
	for (int i = 1; i <= k; i++) {
		if (kf[i] == 0) {
			for (int j = 1; j <= n; j++) {
				if (bj[j] == 0) {
					if (jl[j][0] > b[i][j] + b[i][syg] + c[i]) {
						jl[j][0] = b[i][j] + b[i][syg] + c[i];
						jl[j][1] = i;
					}
				}
			}
		}
	}
}
inline int cz() {
	int minj = 1e9, mins;
	for (int i = 1; i <= n; i++) {
		if (bj[i] == 0) {
			if (jl[i][0] < minj) {
				mins = i;
				minj = jl[i][0];
			}
		}
	}
	return mins;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (long long i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) a[i][j] = 1e9;
		a[i][i] = 0;
		jl[i][0] = 1e9;
	}
	for (int i = 1; i <= m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		a[u][v] = min(a[u][v], w);
		a[v][u] = a[u][v];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> b[i][j];
	}
	int t = n;
	bj[1] = 1;
	syg = 1;
	t--;
	while (t--) {
		px();
		int zdl = cz();
		ans += jl[zdl][0];
		bj[zdl] = 1;
		if (jl[zdl][1] != 0) {
			kf[jl[zdl][1]] = 0;
			for (int i = 1; i <= n; i++) {
				if (bj[i] == 0) {
					if (b[jl[zdl][1]][i] < jl[i][0]) {
						jl[i][0] = b[jl[zdl][1]][i];
						jl[i][1] = 0;
					}
				}
			}
		}
		syg = zdl;
	}
	cout << ans;
	return 0;
}
