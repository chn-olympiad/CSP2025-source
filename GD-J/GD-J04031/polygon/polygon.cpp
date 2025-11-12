#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long  n, a[10010], f[10010], tmp[10010], sum[10010], maxx, ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		maxx = max(maxx, a[i]);
	}
	sort(a + 1, a + 1 + n);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i >= 3) {
			ans = (ans + sum[a[i] + 1]) % mod;
		}
		for (int j = 0; j <= maxx + 1; j++) tmp[j] = f[j];
		for (int j = 0; j <= maxx + 1; j++) {
			if (j + a[i] > maxx) tmp[maxx + 1] = (tmp[maxx + 1] + f[j]) % mod;
			else tmp[j + a[i]] = (tmp[j + a[i]] + f[j]) % mod;
		}
		for (int j = maxx + 1; j >= 0; j--) {
			f[j] = tmp[j];
			sum[j] = (sum[j + 1] + f[j]) % mod;
		}
	}
	cout << ans;
	return 0;
}
