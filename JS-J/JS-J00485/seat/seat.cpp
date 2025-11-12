#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[120];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int R = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int pos;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == R) {
			pos = i;
			break;
		}
	}
	int q = pos / (2 * n), r = pos % (2 * n);
	// cout << q << ' ' << r << '\n';
	if (r == 0) {
		cout << q * 2 << ' ' << 1;
	}
	else if (r <= n) {
		cout << q * 2 + 1 << ' ' << r;
	} 
	else {
		cout << q * 2 + 2 << ' ' << 2 * n - r + 1;
	}
	return 0;
}
