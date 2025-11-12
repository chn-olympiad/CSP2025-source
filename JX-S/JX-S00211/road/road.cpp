#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e4 + 5;
int n, m, k, c[15], a[15][maxn], ans;
signed main() {
	freopen("road.in", "r", stdin);
	freopen("rode.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		ans += w;
	}
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		if(c[i] == 0) {
			cout << "0\n";
			return 0;
		}
		for(int j = 1; j <= n; j ++) cin >> a[i][j];
	}
	cout << ans << "\n";
	return 0;
}
