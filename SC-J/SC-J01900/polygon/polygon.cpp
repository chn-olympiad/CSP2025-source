#include<bits/stdc++.h>
using namespace std;
long long n, a[5010], ans;
bool flag = 1;
const long long mod = 998244353;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) flag = 0;
	}
	sort(a + 1, a + n + 1);
	if (flag) {
		cout << (n - 1) * (n - 2) / 2 % mod;
		return 0;
	} else if (n == 3) {
		if (a[1] + a[2] + a[3] > a[3] * 2) cout << 1;
		else cout << 0;
		return 0;
	} else if (n < 3) cout << 0;
	else {
		long long sum = 0;
		for (int i = 1; i <= n; i++) sum += a[i];
		if (sum > a[n] * 2) ans++;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n - i - 2; j++) {
				if (sum - a[j] > a[n - i] * 2) ans++;
			}
			sum -= a[n - i];
		}
		cout << ans % mod;
	}
	return 0;
}