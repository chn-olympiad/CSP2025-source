#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
const int mod = 998244353;
int n, a[N], ans;
int cnt1[N], cnt2[N];//前i个木棍选择出来长度合大于等于j的方案数 
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= a[1]; i++) {
		cnt1[i] = 1;
	}
	for (int i = 2; i < n; i++) {
		for (int j = a[n] + 1; j >= 0; j--) {
			if (j > a[i])
				cnt2[j] = (cnt1[j - a[i]] + cnt1[j]) % mod;
			else
				cnt2[j] = (cnt1[0] + cnt1[j] + 1) % mod;
			if (a[i+1] + 1 == j) ans = (ans + cnt2[j]) % mod;
		}
		for (int i = 0; i <= a[n] + 1; i++) {
			cnt1[i] = cnt2[i];
		}
	}
	cout << ans;
	return 0;
}