#include <bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505];
long long MOD = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> s[i];
	for (int i = 1;i <= m;i++)
		cin >> c[i];
	long long ans = 1;
	for (int i = 1;i <= n;i++)
	{
		ans *= i % MOD;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
