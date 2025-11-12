#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define N 5005
using namespace std;
ll n, a[N], ans, f[N], tr[N], res;
//f[i]表示有几种方案选木棍凑出i
void add(int x, ll y) {
	for (int i = x; i <= 5000; i += i & -i) tr[i] = (tr[i] + y) % mod;
}
ll query(int x) {
	ll ret = 0;
	for (int i = x; i >= 1; i -= i & -i) ret = (ret + tr[i]) % mod;
	return ret;
}
ll range(int l, int r) {
	if (l > r) return 0;
	return (query(r) - query(l - 1) + mod) % mod;
}
int main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		//尝试让每个元素作为最大值并计算贡献->
		//求出前i-1位有几种选法的和大于a[i]，也就是Sum(f[a[i] + 1] ~ f[5000]) 
		//res表示有几种方法凑出大于5000的数，因为a[i]<=5000
		ans = (ans + range(a[i] + 1, 5000) + res) % mod;
		//加入a[i]
		if (i == n) break;
		res = ((res << 1ll) + range(5000 - a[i] + 1, 5000)) % mod;
		for (int j = 5000; j >= a[i]; j--)
			if (f[j - a[i]]) {
				f[j] = (f[j - a[i]] + f[j]) % mod;
				add(j, f[j - a[i]]);
			}
	}
	cout << ans;
	return 0;
}
