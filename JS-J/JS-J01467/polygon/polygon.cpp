#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mod = 998244353;
int n, ans, a[5010];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < (1ll << n); i++) {
		int sum = 0, mx = -1ll << 62;
		for(int j = 0; j < n; j++) {
			if(i & (1ll << j)) {
				sum += a[j + 1];
				mx = max(mx, a[j + 1]);
			}
		}
		if(sum > mx * 2) {
			ans++; 
			ans %= mod;
		}
	}
	cout << ans % mod << '\n';
	return 0;
}