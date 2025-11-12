#include <bits/stdc++.h>
using namespace std;
int n, m, score;
int a[15][15];
int b[230];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> b[1];
	score = b[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> b[i];
	}
	sort(b, b + n * m - 1, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (m % 2 == 0) {
				a[i][j] = b[(n + 1 - j) * m];
			}
			else {
				a[i][j] = b[n * m];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; i++) {
			if (a[i][j] == score) {
				cout << i << j;
			}
		}
	}
	return 0;
}
