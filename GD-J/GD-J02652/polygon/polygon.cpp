#include <bits/stdc++.h>
using namespace std;

#define spc putchar(32)
#define endl putchar(10)

#define ll long long

const int N = 5005;
const int M = 10020;
const int MOD = 998244353;

int n, fm, ans;
int c[N], f[M], fact[N], ifact[N];

int rd()
{
	char c = getchar(); int s = 0;
	while(!isdigit(c)) c = getchar();
	do s = (s << 1) + (s << 3) + (c ^ 48), c = getchar(); while(isdigit(c));
	return s;
}

void wr(int x)
{
	if(x > 9) wr(x / 10);
	putchar(x % 10 | 48);
}

int power(int x, int y)
{
	int res = 1;
	while(y)
	{
		if(y & 1) res = (ll)res * x % MOD;
		y >>= 1;
		x = (ll)x * x % MOD;
	}
	return res;
}

int C(int n, int m)
{
	return (ll)fact[n] * ifact[m] % MOD * ifact[n-m] % MOD;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = rd();
	f[0] = 1;
	fact[0] = ifact[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		++c[rd()];
		fact[i] = (ll)fact[i-1] * i % MOD;
	}
	ifact[n] = power(fact[n], MOD-2);
	for(int i = n-1; i; --i) ifact[i] = (ll)ifact[i+1] * (i+1) % MOD;
	for(int i = 1; i <= 5000; ++i)
	{
		int cnt = c[i];
		if(!cnt) continue;
		for(int u = 1; u <= cnt; ++u)
		{
			int x = u * i, gs = fm;
			for(int j = max(0, ((i << 1) | 1) - x); j < 10011; ++j) gs = (gs + f[j]) % MOD;
			ans = (ans + (ll)gs * C(cnt, u) % MOD) % MOD;
		}
		for(;cnt; --cnt)
		{
			fm = (fm << 1) % MOD;
			for(int j = 10010; ~j; --j)
			{
				int w = i+j;
				if(w > 10010) fm = (fm + f[j]) % MOD;
				else f[w] = (f[w] + f[j]) % MOD;
			}
		}
	}
	wr(ans);
	return 0;
}
