#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, MOD = 998244353;
long long n, a[N], ans, f[N], all; 
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n;
	all = f[0] = 1;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		long long tmp = 0;
		for (int j = 0; j <= a[i]; j ++)
			tmp = (tmp + f[j]) % MOD;
		for (int j = a[n]; j >= a[i]; j --)
			f[j] = (f[j - a[i]] + f[j]) % MOD;
		ans = (ans + all - tmp + MOD * 2) % MOD;
		all = (all << 1) % MOD;
	}
	cout << ans;
	return 0;
}
