#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, K = 15, M = 1e6 + 10;
int n, m, k;
int u[M], v[M], w[M];
int c[K], a[N][K];
bool st[N], b[K];
int ii;
int main() {		
	freopen("road.in", "r", stdin);
	freopen("road.out", "w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++ ) cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= k; i ++ ) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++ ) cin >> a[i][j];
	}
	int mi = 0x3f3f3f3f, mil;
	for (int i = 1; i <= m; i ++ ) {
		mi = min(mi, w[i]);
		mil = i;
	}
	int sum = 0;
	int l = 1;
	for(int i = 1; i <= n; i ++ ) {
		int mi = 0x3f3f3f3f, mil;
		st[l] = 1;
		for (int j = 1; j <= m; j ++ ) {
			if (st[i] == 1) continue;
			int mi2 = mi;
			if (u[i] == l || v[i] == l) mi = min(mi, w[i]);
			if (mi != mi2) mil = i;
		}	
		for (int j = 1; j <= k; j ++ ) {
			for (int r = 1; r <= n; r ++ ) {
				int mi2 = mi;
				if (b[j] == 1) mi = min(mi, a[j][r]);
				else mi = min(mi, a[j][r] + c[j]);
				if (mi != mi2) mil = m + j;
			}
		}
		if (mi == 0x3f3f3f3f) break;
		if (mil > m) b[mil - m] = 1;
		sum += mi;
	}
	cout << sum << endl;
	return 0;
}
