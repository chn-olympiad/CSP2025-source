#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int big = 0;
	int n, m;
	cin >> n >> m;
	int u;
	cin >> u;
	for (int i = 0; i < n * m - 1; i++) {
		int t;
		cin >> t;
		if (t > u) {
			big++;
		}
	}
	big++;
	int ans1 = 1, ans2 = 1, p, q;
	if (big % n == 0) {
		p = big / n;
		if (p % 2 == 1) {
			cout << p << ' ' << 1;
			return 0;
		} else {
			cout << p << ' ' << n;
			return 0;
		}
	} else {
		p = big / n + 1;
	}
	q = big % n;
	if (p % 2 == 1) {
		cout << p << ' ' << q;
		return 0;
	} else {
		cout << p << ' ' << n - q + 1;
		return 0;
	}
	return 0;
}