#include <bits/stdc++.h>

#define int long long

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = r; i >= l; i--)

using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5, K = 15;

vector<pair<int, int>> e[N];

int n, m, k, cost[K][N];

signed main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
//	freopen("road.ans", "w", stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	cin >> n >> m >> k;
	
	rep (i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	
	rep (i, 1, k) {
		rep (j, 0, n) {
			cin >> cost[i][j];
		}
	}
	
	return 0;
}

/*
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
return 0;
*/
