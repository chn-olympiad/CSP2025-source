#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef double f16;
typedef pair <int, int> pii;

const int N = 5e2 + 10, P = 998244353;
int n, m, s[N], c[N];
i64 fac[N], fac_inv[N];

i64 qpow (i64 b, int e)
{
	i64 res = 1;
	while (e)
	{
		if (e & 1) res = res * b % P;
		b = b * b % P;
		e >>= 1; 
	}
	return res % P;
}

void fac_init (int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; i ++) fac[i] = fac[i - 1] * i % P;
	fac_inv[n] = qpow (fac[n], P - 2);
	for (int i = n - 1; ~i; i --) fac_inv[i] = fac_inv[i + 1] * (1ll + i) % P;
}

i64 C (int n, int m) { return fac[n] * fac_inv[m] % P * fac_inv[n - m] % P; }

void Sub_n10 ()
{
	vector <int> p (n + 1);
	for (int i = 1; i <= n; i ++) p[i] = i;
	int ans = 0;
	do
	{
		int cnt = 0;
		for (int i = 1; i <= n; i ++)
			if (cnt >= c[i] || !s[i]) cnt ++;
		ans += (n - cnt >= m);
	}
	while (next_permutation (p.begin () + 1, p.end ()));
	cout << ans;
}

void Sub_s1 ()
{
	fac_init (n);
	cout << fac[n] * fac_inv[n - m] % P; 
}

int main ()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	bool sub_s1 = true;
	for (int i = 1; i <= n; i ++)
	{ char c; cin >> c; s[i] = c - '0', sub_s1 &= s[i]; }
	for (int i = 1; i <= n; i ++) cin >> c[i];
	if (n <= 10) return Sub_n10 (), 0;
	if (sub_s1) return Sub_s1 (), 0;
	return 0;
}

/*

*/
