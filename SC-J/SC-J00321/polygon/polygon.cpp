#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, mod = 998244353;
long long n, m[N], ans, k;
long long C (int a, int b) {
	int cnt1 = 1, cnt2 = 1, cnt3 = 1;
	for (int i = 1; i <= a; i++) {
		cnt1 *= i;
		cnt1 %= mod; 
	}
	for (int i = 1; i <= b; i++) {
		cnt2 *= i;
		cnt2 %= mod;
	}
	for (int i = 1; i <= a - b; i++) {
		cnt3 *= i;
		cnt3 %= mod;
	}
	return (cnt1 / cnt2 / cnt3) % mod;
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	long long maxn = -1e9;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		maxn = max (maxn, m[i]); 
	}
	if (n < 3) {
		cout << 0 << '\n';
		return 0;
	}
	else if (n == 3) {
		sort(m + 1, m + n + 1);
		if (m[1] + m[2] + m[3] > 2 * m[3]) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
		return 0;
	}
	long long ans = 1;
	for (int i = n; i >= 3; i--) {
		ans += C(i, 3);
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}