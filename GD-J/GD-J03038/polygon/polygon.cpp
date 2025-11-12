#include <bits/stdc++.h>
using namespace std;
long long jiecheng(int n) {
	long long res = 1;
	for(int i = 2; i <= n; ++i) {
		res *= 1LL * i;
		res %= 998244353;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, cnt1 = 0;
	cin >> n;
	vector<int> a(n + 1), s(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] == 1) cnt1++;
	}
	if(n == 3) {
		int maxi = -1, sum = 0;
		for(int i = 1; i <= n; ++i) maxi = max(maxi, a[i]), sum += a[i];
		if(sum > 2 * maxi) cout << 1 << '\n';
		else cout << 0 << '\n';
		return 0;
	}
	if(cnt1 == n) {
		long long res = 0;
		for(int i = 3; i <= n; ++i) {
			long long ans = 1;
			for(int j = i + 1; j <= n; ++j) {
				ans *= j;
				ans %= 998244353;
			}
			ans /= jiecheng(n - i);
			res += ans;
			res %= 998244353;
		}
		cout << res << '\n';
		return 0;
	}
	return 0;
}
