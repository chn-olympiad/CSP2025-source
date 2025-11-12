#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int arr[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> arr[i];
	}
	r = arr[1];
	sort(arr + 1, arr + 1 + n * m, [](int a, int b){return a > b;});
	for (int i = 1; i <= n * m; i++) {
		if (arr[i] == r) {
			if ((i - 1) / n % 2) {
				cout << (i - 1) / n + 1 << ' ' << n - (i - 1) % n;
			} else {
				cout << (i - 1) / n + 1 << ' ' << (i - 1) % n + 1;
			}
			return 0;
		}
	}
	return 0;
} 
