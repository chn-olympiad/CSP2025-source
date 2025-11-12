#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], s[15][15];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i];
	}
	int Rscore = a[1], l = n * m;
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= m; ++i) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; ++j) {
				s[j][i] = a[l--];
			}
		} else {
			for (int j = n; j >= 1; --j) {
				s[j][i] = a[l--];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == Rscore) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
