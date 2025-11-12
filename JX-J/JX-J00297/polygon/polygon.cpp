#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5, mod = 998244353;
int n, a[maxn], ans, maxx, sum[maxn], dp[maxn];
int C(int x, int y) {
	int p = 1;
	for(int i = x; i >= 1; i --) p = p * i % mod;
	int q = 1;
	for(int i = y; i >= y - x + 1; i --) q = q * i % mod;
	return q / p;
}
signed main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
		maxx = max(maxx, a[i]);
	}
	if(maxx == 1) {
		int res = 0;
		for(int i = 1; i <= n; i ++) {
			if(a[i] == 1) res ++;
		}
		for(int i = 3; i <= res; i ++) {
			ans += C(i, res);
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	if(n == 3) {
		if(sum[n] > 2*maxx) cout << "1\n";
		else cout << "0\n";
		return 0;
	}
	return 0;
}
