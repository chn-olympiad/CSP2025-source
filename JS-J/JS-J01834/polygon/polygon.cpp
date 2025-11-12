#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353

ll f[5005][5005];
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	f[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 5003; j++) {
			(f[i + 1][min(j + a[i], 5003)] += f[i][j]) %= mod;
			(f[i + 1][j] += f[i][j]) %= mod;
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= 20; j++) {
	// 		cerr << f[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		for (int j = a[i] + 1; j <= 5003; j++) {
			(ans += f[i][j]) %= mod;
		}
	}
	printf("%lld", ans);
	return 0;
}