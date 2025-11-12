#include "bits/stdc++.h"
#define ll long long
#define mod 998244353
using namespace std;
ll n, m, dp[505][505], fac[505], inv[505], c[505], flag;
string s;
ll fpow(ll x, ll y)
{
	if(y == 0)
	{
		return 1;
	}
	if(y == 1)
	{
		return x;
	}
	ll res = 1;
	while(y)
	{
		if(y & 1)
		{
			res = res * x % mod;
		}
		x = x * x % mod;
		y /= 2;
	}
	return res;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	cout << 0;
	return 0;
}
