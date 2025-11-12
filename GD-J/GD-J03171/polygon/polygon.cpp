#include <bits/stdc++.h>
using namespace std;

long long check(int arr[], int n, int max) {
	if (max < 0) return pow(2, n);
	if (n == 1) return arr[0] > max ? 1 : 0;
	return check(arr, n - 1, max) + check(arr, n - 1, max - arr[n - 1]);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[5000];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	long long ans = 0;
	for (int i = 2; i < n; i++) {
		ans += check(a, i, a[i]);
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}
