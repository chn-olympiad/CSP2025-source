#include <bits/stdc++.h>
using namespace std;

/*
f[i] = cnt(sum(i - 1) >= a[i])
*/

int n;
int a[5005], f[5005], ans = 0;
int s[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (n <= 400){
		sort(a+1, a+n+1);
		for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
		f[a[1] + 1] = 0, f[a[2] + 1] = 0;
		for (int i = 3; i <= n; ++i) {
			int k = (1 << (i - 1)) - 1;
				while (k > 0) {
					int _res = 0;
					int j = k, idx = 1; while (j > 0) {
						_res += a[idx] * (j & 1);
						j >>= 1; ++idx;
					} if (_res > a[i]) ++f[a[i] + 1];
					--k;
				} ans += f[a[i] + 1];
		} cout << ans;
	} else {
		long long int ans = 1;
		for (int i = 1;i <= n;i++) {
			ans *= 2; ans %= 998244353;
		} ans -= n + 1 + n * (n - 1) /2; cout << ans;
	}
	
	
	return 0;
} 