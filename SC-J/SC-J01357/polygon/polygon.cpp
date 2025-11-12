#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5e3 + 5;

const ll mod = 998244353;

int n, a[maxn];

ll f[2][maxn];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int maxv = a[n] + 1;
	ll ans = 0;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		int now = i & 1, last = (i - 1) & 1;
		for(int j = 0; j <= maxv; j++) f[now][j] = f[last][j];
		for(int j = 0; j <= maxv; j++)
			f[now][min(j + a[i], maxv)] = (f[now][min(j + a[i], maxv)] + f[last][j]) % mod;
		for(int j = a[i] + 1; j <= maxv; j++) ans = (ans + f[last][j]) % mod;
	}
	cout << ans << "\n";
	return 0;
}