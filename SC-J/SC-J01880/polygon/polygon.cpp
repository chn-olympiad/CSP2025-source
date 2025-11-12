#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	long long arr[501], maxx = -2, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < maxx) maxx = arr[i];
		sum += arr[i];
	}
	if (n <= 3) {
		maxx *= 2;
		if (n < 3) cout << 0;
		else {
			if (sum > maxx) cout << 1;
			else cout << 0;
		}
		return 0;
	} else {
		long long sum2 = 1;
		for (int i = n; i >= 4; i--) {
			sum2 *= i;
		}
		cout << sum2;
		return 0;
	}

}