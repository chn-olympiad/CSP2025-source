#include <iostream>
#include <cstdio>
using namespace std;
const int N = 5e3+5, mod = 998244353;
long long n, ans, x[N], f[N];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) f[i] = (f[i-1] * i) % mod;
	for (int i = 3; i <= n; i++) ans += (f[n] / f[i]) % mod;
	cout << ans;
	return 0;

}
