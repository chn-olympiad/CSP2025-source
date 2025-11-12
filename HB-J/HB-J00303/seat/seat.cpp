#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a[N], res[N][N];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int a1 = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2 == 1) res[j][i] = a[++cnt];
			else res[n - j + 1][i] = a[++cnt];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (res[i][j] == a1) {
				cout << j << " " << i << "\n";
			}
		}
	}
	return 0;
}
