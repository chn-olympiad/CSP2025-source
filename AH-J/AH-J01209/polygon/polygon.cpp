#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> arr(n + 10, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	if (n == 0 || n == 1 || n == 2) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		if (arr[1] + arr[2] + arr[3] > max(arr[1], max(arr[2], arr[3])) * 2) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	cout << 0;
	return 0;
}

