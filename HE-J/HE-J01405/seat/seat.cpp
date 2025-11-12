#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N * N], cnt;
int n, m, R;
bool cmp (int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	R = a[1];
	sort (a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == R) {
			if (((i - 1) / n + 1) % 2 == 1)
				cout << (i - 1) / n + 1 << ' ' << i - ((i - 1) / n * n);
			else
				cout << (i - 1) / n + 1 << ' ' << n - (i - (i - 1) / n * n) + 1;
			break;
		}
	}
	return 0;
}
