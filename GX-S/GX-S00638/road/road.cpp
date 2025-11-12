#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, k, a[N][N], vos[15][N];
int main () {
	memset (a , 0x3f, sizeof(a));
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++) {
		int x, y, w;
		cin >> x >> y >> w;
		a[x][y] = w;
		a[y][x] = w;
	}
	
	for (int i = 1; i <= k; i ++) {
		int sdfg;
		cin >> sdfg;
		for (int j = 1; j <= n; j ++)
			cin >> vos[i][j];
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == j)
				continue;
			for (int x = 1; x <= k; x ++) {
				a[i][j] = min (a[i][j], vos[x][i] + vos[x][j]);
				a[i][j] = min (a[i][j], a[j][i]);
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
