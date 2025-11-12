#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r, p = 0, x, y;
	cin >> n >> m >> r;
	for (int i = 2; i <= n * m; ++i) {
		int c;
		cin >> c;
		if (c > r) ++p;
	}
	x = p / m, y = p % m;
	if (x & 1) y = m - 1 - y;
	cout << x + 1 << " " << y + 1;
	return 0;
}

