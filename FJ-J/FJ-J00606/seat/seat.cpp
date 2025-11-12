#include <bits/stdc++.h>
using namespace std;
int a[105], b[15][15];
bool cmp(int x, int y) {
	return x > y;
}
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t = 0, x;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			b[i][j] = a[++t];
			if (b[i][j] == x) {
				cout << i << " " << j;
				return 0;
			}
		}
		i++;
		for (int j = n; j >= 1; j--) {
			b[i][j] = a[++t];
			if (b[i][j] == x) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
