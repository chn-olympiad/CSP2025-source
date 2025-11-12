#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, m, a[N], q, b;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	q = a[1];
	sort(a + 1, a + 1 + n*m);
	for (int i = n * m; i >= 1; i--) {
		if (q == a[i]) {
			b = n*m - i + 1;
			break;
		}
	}
	int c = b / n;
	int d = b - c * n;
	if (d) {
		cout << c + 1 << ' ';
	} else
		cout << c << ' ';
	if (c % 2 == 0) {
		if (d) {
			cout << d;
		} else
			cout << 1;
		cout << ' ';
	} else {
		if (d) {
			cout << n - d + 1;
		} else cout << n;
	}
	return 0;
}
