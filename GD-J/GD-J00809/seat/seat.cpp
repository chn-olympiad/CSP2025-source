#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int a[N], r, rk;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			rk = i;
			break;
		}
	}
	int row = (rk + n - 1) / n, col;
	if (row & 1) col = (rk + n - 1) % n + 1;
	else col = n - ((rk - 1) % n);
	cout << row << ' ' << col;
	return 0;
}
