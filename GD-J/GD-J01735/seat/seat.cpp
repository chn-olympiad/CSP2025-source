#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N], n, m;
int b[N][N];

inline void dfs (int x, int y, int idx) {
	if (idx == n * m + 1) return ;
	b[x][y] = a[idx];
	if (x + 1 <= n && !b[x + 1][y]) dfs (x + 1, y, idx + 1);
	else if (x - 1 >= 1 && !b[x - 1][y]) dfs (x - 1, y, idx + 1);
	else dfs (x, y + 1, idx + 1);
} 

inline bool kp (int x, int y) {
	return x > y;
}

signed main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) cin >> a[i];
	int t = a[1];
	sort (a + 1, a + 1 + n * m, kp);
	dfs (1, 1, 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (b[i][j] == t) {
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}

/*
3 3
94 95 96 97 98 99 100 93 92
*/

/*

*/
