#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, arr[5003];
int p[5003];
int sum[2][5003];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		p[i] = p[i - 1] * 2 % mod;
	}
	sort(arr + 1, arr + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + p[i - 1]) % mod;
		ans = (ans - i + mod) % mod;
		for (int j = 0; j <= arr[i]; j++) {
			ans = (ans - sum[1][j] + mod) % mod;
		}
		for (int j = 5000; j >= arr[i]; j--) {
			sum[1][j] += sum[0][j - arr[i]];
			sum[1][j] %= mod;
			sum[1][j] += sum[1][j - arr[i]];
			sum[1][j] %= mod;
		}
		sum[0][arr[i]]++;
	}
	cout << ans;
	return 0;
}
