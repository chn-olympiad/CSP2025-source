#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, u[N], v[N], w[N];
int c[15][N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) cin >> u[i] >> v[i] >> w[i], sum += w[i]; 
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> c[i][j];
	cout << sum;
	return 0;
}
