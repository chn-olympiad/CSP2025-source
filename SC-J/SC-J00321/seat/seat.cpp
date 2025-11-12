#include <bits/stdc++.h>
using namespace std;
int a[200], n, m;
int c[15][15];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r = a[1], x, y;
//	cout << r << endl;
	sort(a + 1, a + n * m + 1, greater<int>());
	int cnt = 1;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				c[j][i] = a[cnt];
				cnt++;
			}
		}
		else {
			for (int j = n; j >= 1; j--) {
				c[j][i] = a[cnt];
				cnt++;	
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c[i][j] == r) {
				x = j, y = i;
			}
//			cout << c[i][j] << " ";
		}
//		cout << "\n";
	}
	cout << x << " " << y << "\n";
	return 0;
} 