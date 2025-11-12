#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], ans = 1;;
long long mod = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		ans *= 2;
		ans %= mod;
	}
	ans -= n * (n - 1) * (n - 2) / 6;
	ans -= n * (n - 1) / 2;
	ans -= n;
	cout << (ans + mod) % mod;
	return 0;
}
