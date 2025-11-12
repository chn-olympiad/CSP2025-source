#include <bits/stdc++.h>
using namespace std;
int a[121];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int r, s;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + m * n + 1, greater<int>());
	for (int i = 1; i <= m * n; i++) {
		if (a[i] == r) {
			s = i;
			break;
		}
	}
	int nr = s % n, mr = s / n + (s % n != 0);
	bool order = mr % 2;
	if (order) {
		cout << mr << ' ' << nr + (nr == 0) * n;
	}else {
		cout << mr << ' ' << n - nr + 1;
	}
	return 0;
} 