#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int mod = 998244353, N = 505;

int n, m, c[N];
char str[N];
LL jc[N], inv[N];

LL qpow(LL x, LL y)
{
	LL t = 1;
	while(y)
	{
		if(y & 1) t = (t * x) % mod;
		y >>= 1;
		x %= mod;
		x = x * x % mod;
	}
	
	return t;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);
	for(int i = 1; i <= n; i++) 
	{
		scanf("%d", &c[i]);
	}
		
	jc[1] = 1;
	for(int i = 2; i <= n; i++)
		jc[i] = (jc[i - 1] * i) % mod;
	
	inv[n] = qpow(jc[n], mod - 2);	
	
	for(int i = n - 1; i >= 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
	
	int k = 0;
	for(int i = 1; i <= n; i++) if(c[i] == 0) k++; 
	
	LL ans = (jc[n] * inv[n - m]) % mod;
	printf("%lld\n", ans);
	
	return 0;	
}
