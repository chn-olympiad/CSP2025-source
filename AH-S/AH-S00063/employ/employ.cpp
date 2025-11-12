#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,s[505],c[505],C[505][505],fac[505];
namespace XZA
{
	void solve()
	{
		int md = 998244353;
		fac[0] = 1;
		for (int i = 1;i <= 500;i++) fac[i] = fac[i - 1] * i % md;
		C[1][0] = C[1][1] = 1;
		for (int i = 2;i <= 500;i++)
		{
			C[i][0] = 1;
			for (int j = 1;j <= i;j++)
			{
				 C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % md;
			 }
		}
		int s = 0;
		for (int i = 1;i <= n;i++)
		{
			if (c[i] != 0) s++;
		}
		cout << C[s][m] * fac[m] % md * fac[n - m] % md;
	}
}
signed main()
{
	cin >> n >> m;
	int mic = INT_MAX;
	for (int i = 1;i <= n;i++)
	{
		char c;
		cin >> c;
		s[i] = c - '0';
		mic = min(mic,s[i]);
	}
	for (int i = 1;i <= n;i++) cin >> c[i];
	int mi = INT_MAX;
	for (int i = 1;i <= n;i++) mi = min(mi,c[i]);
	if (mic == 1) XZA::solve();
	return 0;
}
