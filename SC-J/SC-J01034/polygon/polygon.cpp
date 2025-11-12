#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3;
const int maxv = 5e3;
const int mod = 998244353;


int n, ans;
int a[maxn + 5];
int f[maxn + 5][maxv + 5];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <= maxv; ++j)
			f[i][j] = (f[i-1][j] + f[i-1][max(j-a[i], 0)] + (a[i] > j)) % mod;
	}
	
	for(int i = 1; i <= n; ++i)
		ans = (ans + f[i-1][a[i]]) % mod;
	cout << ans << endl;
	return 0;
}