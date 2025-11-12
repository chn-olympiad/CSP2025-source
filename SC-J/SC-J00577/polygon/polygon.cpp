#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
const int N = 5010;
int n, a[N], f[N], p[N], ans;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	p[0] = 1;
	for (int i = 1; i <= 5001; ++i)
		p[i] = (p[i - 1] * 2) % MOD;
	for (int i = 1; i < n; ++i) {
		for (int j = 5001; j > a[i]; --j)
			(f[j] += f[j - a[i]]) %= MOD;
		for (int j = a[i]; j; --j)
			(f[j] += p[i - 1]) %= MOD;
		(ans += f[a[i + 1] + 1]) %= MOD;
	}
	printf("%lld\n", ans);
	fclose(stdin), fclose(stdout);
	return 0;
}