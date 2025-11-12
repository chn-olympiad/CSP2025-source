#include <bits/stdc++.h>
using namespace std;
long long init(int n) {
	long long k = 0;
	long long p = 1;
	for (int i = 1; i <= n; ++i) {
		k += p;
		p *= 2;
	}
	return k;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	long long k = init(n);
	int a[5010];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	long long ans = 0;
	for (int akm = 1; akm <= k; ++akm) {
		int t = akm;
		int mx = -1;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (t % 2) {
				mx = max(mx, a[i]);
				sum += a[i];
			}
			t >>= 1;
		}
		if (sum > 2 * mx)
			ans = (ans + 1) % 998244353;
	}
	cout << ans;
	return 0;
}
