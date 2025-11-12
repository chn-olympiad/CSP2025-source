#include<iostream>
#include<algorithm>
using namespace std;
int n, a[5005], sum[5005], fsum[5005];
long long ans;
void dfs(int idx, int mx, int sum, bool d) {
	if (sum > 2 * mx && d) ++ans;
	if (idx > n) {
		return;
	}
	dfs(idx + 1, max(mx, a[idx]), sum + a[idx], 1);
	dfs(idx + 1, mx, sum, 0);
}
long long fac[5005];
const int MOD = 998244353;
long long ksm(int a, int b) {
	if (b == 1) return a;
	long long t = ksm(a, b / 2);
	return t * t % MOD * (b % 2 ? a : 1) % MOD;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	fac[0] = 1;
	for (int i = 1; i <= 5000; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
	if (n <= 20) {
		dfs(1, 0, 0, 0);
		cout << ans;
	} else {
		for (int i = 3; i <= n; i++) {
			ans = (fac[n] * ksm(fac[n - i], MOD - 2) % MOD * ksm(fac[i], MOD - 2) % MOD + ans) % MOD;
		}
		cout << ans;
	}
	return 0;
}
//TLE or WA 64pts
//66666
