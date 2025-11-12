#include <bits/stdc++.h>
using namespace std;
int a[15][15];
bool cmp(const int &x, const int &y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (i == 0 && j == 0) {
				s = a[i][j];
			}
		}
	}
	sort(*a, *a + n * m, cmp);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == s) {
				cout << (i % 2 ? m - j : j + 1) << " ";
				cout << i + 1;
				return 0;
			}
		}
	}
}
