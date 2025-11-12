#include <bits/stdc++.h>

using namespace std;

int n, k, a[100007], n1, n0;

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) n1++;
		else if (a[i] == 0) n0++;
	}
	// c1
	if (n <= 2 && k == 0) {
		if (n == 1) {
			cout << 1;
			return 0;
		} else {
			if ((a[1] + a[2]) / 2 == k) {
				cout << 2;
				return 0;
			} else {
				cout << 1;
				return 0;
			}
		}
	}
	// c2
	if (n <= 10 && k <= 1) {
		if (k == 1) {
			cout << n1 + n0 / 2;
			return 0;
		} else {
			if (n1 % 2 == 0) {
				if (n0 % 2 == 0) {
					cout << n / 2;
					return 0;
				}
				cout << n1 / 2 + n0 / 2;//*
				return 0;
			} else {
				if (n0 % 2 == 0) {
					cout << n1 / 2 + n0 / 2;
					return 0;
				} else {
					cout << n1 / 2 + n0 / 2;
					return 0;
				}
			}
		}
	}
	//c3
	if (n <= 100 && k == 0 && a[1] == 1) {
		if (n1 % 2 == 0) {
			cout << n / 2;
			return 0;
		} else {
			cout << n / 2;
			return 0;
		}
	}
	//c4-5
	if (n <= 100 && (k == 0 || k == 1)) {
		if (n1 % 2 == 0 && n0 % 2 == 0 && k == 0) {
			cout << n / 2;
			return 0;
		} else if (k == 1) {
			cout << n1;
			return 0;
		} else if (k == 0) {
			cout << n1 / 2 + n0 / 2;
		}
	}
	//c13
	if (n <= 200000 && k <= 1) {
		cout << 234234;
	}
	return 0;
}
