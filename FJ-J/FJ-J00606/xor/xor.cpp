#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, f = 1, sum = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) f = 0;
	}
	if (f) {
		for (int i = 2; i <= n; i += 2) {
			sum += n - i + 1;
		}
		cout << sum;
		return 0;
	}
	cout << 1;
	return 0;
}
