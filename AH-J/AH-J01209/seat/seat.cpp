#include <bits/stdc++.h>
using namespace std;

int n, m;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	vector<int> arr(n * m + 10, 0);
	for (int i = 1; i <= n * m; i++) {
		cin >> arr[i];
	}
	int rChengJi = arr[1];
	stable_sort(&arr[1], &arr[n * m] + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (arr[i] == rChengJi) {
			cout << ceil(i * 1.0 / n) << " ";
			if (int(ceil(i * 1.0 / n)) % 2 == 0) {
				if (i % n == 0) {
					cout << 1;
				} else {
					cout << n - i % n + 1;
				}
			} else {
				if (i % n == 0) {
					cout << n;
				} else {
					cout << i % n;
				}
			}
			break;
		}
	}
	return 0;
}
