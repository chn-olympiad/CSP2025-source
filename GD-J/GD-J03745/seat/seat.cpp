#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s[101] = {0}, a[100];
	cin >> n >> m;
	for (int i = 0; i <= n * m; i++) {
		cin >> a[i];
		s[100 - a[i]] = 1;
	}
	for (int i = 0; i <= 100; i++) {
		if (100 - i == a[0] && s[i] == 1) {
			int col = ceil((i + 1) * 1.0 / n);
			int row;
			if (col % 2 == 1) {
				row = (i + 1) % n;
				if (row == 0) row = n;
			} else {
				row = n - (i + 1) % n + 1;
			}
			cout << col << " " << row;
			break;
		}
	}
	return 0;
}

