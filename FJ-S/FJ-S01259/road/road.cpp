#include <bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;

const int M = 1e6+5, N = 1e4+5, K = 1e1+5;
int n, m, k, c[M], a[K][N];

struct Roads {
	int u, v, w;
} r[M];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	IOS;
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++) {
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for(int i=1; i<=k; i++) {
		cin >> c[i];
		for(int j=2; j<=n+1; j++) {
			cin >> a[i][j];
		}
	}
	
	return 0;
}

