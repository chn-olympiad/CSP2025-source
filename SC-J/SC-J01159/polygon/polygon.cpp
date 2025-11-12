#include<bits/stdc++.h>
#define itn int
#define pii pair<int,int>
#define el cout<<"\n"
#define fi first
#define se second
#define N 5010ll
#define mod 998244353
#define int long long
using namespace std;
int n, a[N], f[N + 50], ans;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = a[i] + 1; j <= N; j++)
			ans = (ans + f[j]) % mod;
		for (int j = N; ~j; j--)
			f[min(N, j + a[i])] = (f[min(N, j + a[i])] + f[j]) % mod;
	}
	cout << ans;
	return 0;
}
//I ak CSP-J!!!Really!!!!
//luogu @Sine_Func , uid:975724