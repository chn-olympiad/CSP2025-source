// the last CSP-S
// rp++
// 写了个容斥假完了
// 懒得喷 
#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 510, mod = 998244353;
int n, m, c[N], cnt[N], ans, p[N];
char s[N];

LL fac[N];
void init()
{
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 1; i <= n; i++) 
	{
		scanf("%d", &c[i]);
		cnt[c[i]]++;
	}
	for(int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
	init();
	
	if(m == 1)
	{
		int s0 = 0;
		ans = 1;
		for(int i = 1; i <= n; i++)
			if(s[i] == '0') s0++;
			else ans = 1ll * ans * (cnt[i - 1] - (i - 1 - s0)) % mod;
		cout << (fac[n] - ans * fac[s0] % mod + mod) % mod << endl;
	}
	else if(m == n)
	{
		for(int i = 1; i <= n; i++)
			if(s[i] == '0' || !c[i])
				return puts("0"), 0;
		cout << fac[n] << endl;
	}
	else
	{
		for(int i = 1; i <= n; i++) p[i] = i;
		do
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
				if(s[i] == '0' || cnt >= c[p[i]])
					cnt++;
			if(cnt <= n - m) ans++;
		}
		while(next_permutation(p + 1, p + n + 1));
		cout << ans << endl;
	}
	return 0;
}

