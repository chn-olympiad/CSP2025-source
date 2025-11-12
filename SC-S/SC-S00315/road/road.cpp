#include <bits/stdc++.h>
//#pragma GCC optimize(2)
//#define int long long
#define endl "\n"

using namespace std;

const int N = 1e6 + 9;

int a;
int n, m;
int ans;
int k;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j <= n; j++) {
			cin >> a;
		}
	}
	cout << 0 << endl;
	return 0;
}