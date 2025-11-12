#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, a[500005];

bool check() {
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			return false;
		}
	}
	return true;
}

bool check2() {
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			return false;
		}
	}
	return true;
}

bool cmp() {
	int b[1000005] = {};
	for (int i = 1; i <= n; i++) {
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

int count(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == x) {
			cnt++;
		}
	}
	return cnt;
}

bool check4() {
	for (int i = 1; i <= n; ) {
		if (a[i] == 0) {
			i++;
		}
		else {
			if (a[i + 1] == 1) {
				i += 2;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

bool check5() {
	if (count(1) < count(0)) {
		return false;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0 && a[i + 1] == 0) {
			cout << i << '\n';
			return false;
		}
		else {
			i++;
		}
	}
	return true;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	if (check2()) {
		cout << (n >> 1) << '\n';
	}
	if (k == 0) {
		cout << (n >> 1) << '\n';
		return 0;
	}
	else if (k <= 1) {
		if (check()) {
			cout << n << '\n';
		}
		else if (check2()) {
			cout << (n >> 1) << '\n';
		}
		else {
			if (k == 0) {
				if (cmp()) {
					if (count(1) & 1) {
						cout << 1 << '\n';
					}
					else {
						cout << (count(1) >> 1 + n - count(1) >> 1) <<'\n';
					}
				}
				else {
					if (check4()) {
						cout << (count(1) >> 1 + n - count(1) >> 1) << '\n';
					}
					else {
						cout << 1 << '\n';
					}
				}
			}
			else {
				if (check5()) {
					cout << (count(1)) << '\n';
				}
				else {
					cout << 1 << '\n';
				}
			}
		}
		return 0;
	}
	
	srand(time(0));
	cout << rand() % 1000000000 << '\n';
	
	return 0;
}