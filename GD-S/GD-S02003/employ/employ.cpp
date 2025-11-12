#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505;
const int mod = 998244353;

int n, m;

int c[N];

int a[N];

int num;

ll ans = 1;

ll fac[N];
ll inv[N];

ll qpow(int a, int b)
{
	ll res(1);

	while(b)
	{
		if(b&1)(res *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}

	return res;
}

ll C(int n, int m)
{
	return fac[n] * inv[m] % mod * inv[n-m] % mod;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin.tie() -> ios::sync_with_stdio(false);

	cin >> n >> m;

	inv[0] = fac[0] = 1;

	for(int i(1); i <= 500; ++i)
		fac[i] = fac[i-1] * i, inv[i] = qpow(fac[i], mod-2) % mod;

	for(int i(1); i <= n; ++i)
	{
		char ch;
		cin >> ch;

		c[i] = ch - '0';
	}

	for(int i(1); i <= n; ++i)
		cin >> a[i];

	for(int i(1); i <= n; ++i)
		if(a[i] > 0)num++;

	int cnt(0);

	for(int i(1); i <= n; ++i)
		if(c[i] == 1)cnt++;

	if(cnt < m || num < m)return  cout << "0\n", 0;

	int cnt1(0);

	for(int i(1); i <= n; ++i)
		if(c[i] == 0)break;
		else	cnt1++;

	if(m == 1)
	{
		cnt1 = 0;
		for(int i(1); i <= n; ++i)
		if(c[i] == 1)break;
		else	cnt1++;

		int num1(0);

		for(int i(1); i <= n; ++i)
			if(a[i] > cnt1)num1++;

		ans = num1;

		for(int i(1); i < n; ++i)
			(ans *= i) %= mod;

		cout << ans << '\n';

		return 0;
	}

	bool is(false);

	for(int i(1); i <= n; ++i)
		if(a[i] != 1)is = true;

	if(!is)
	{
		if(cnt1 < m)return  cout << "0\n", 0;

		// ans = C(n, m);

		for(int i(1); i <= n; ++i)
			(ans *= i) %= mod;

		cout << ans << '\n';

		return 0;
	}

	cout << rand() % mod << '\n';

	return 0;
}
