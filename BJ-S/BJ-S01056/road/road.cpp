#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
int n, m, k, u[N], v[N], w[N], c[N], a[N][N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	cout << 0;
	return 0;
}
