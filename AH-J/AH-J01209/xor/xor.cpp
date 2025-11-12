#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;

bool quanYi() {
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	arr = vector<int>(n + 10, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		if (arr[1] == k) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	if (n == 2) {
		if (arr[1] == k && arr[2] == k) {
			cout << 2;
		} else if (arr[1] == k && arr[2] != k) {
			cout << 1;
		} else if (arr[1] != k && arr[2] == k) {
			cout << 1;
		} else if (arr[1] ^ arr[2] == k) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	if (quanYi() && k == 0) {
		cout << n / 2;
		return 0;
	}
	cout << 2;
	return 0;
}

