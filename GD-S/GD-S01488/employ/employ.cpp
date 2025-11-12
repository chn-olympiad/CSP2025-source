#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
int n, m, c[N], t, tt[N];
long long ans;
char s[N];
bool p[N];
void ff(int aa, int bb)
{
	if(t-aa+1+bb < m)
		return;
	if(aa == t+1)
	{
		ans++;
		return;
	}
	for(int i = 1; i <= n; i++)
		if(p[i] == false)
		{
			p[i] = true;
			if(c[i] > tt[aa]+(aa-bb-1))
				ff(aa+1, bb+1);
			else
				ff(aa+1, bb);
			p[i] = false;
		}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s+1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	sort(c+1, c+n+1);
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '0')
			tt[t+1]++;
		else
		{
			t++;
			tt[t+1] = tt[t];
		}
	}
	ff(1, 0);
	for(int i = n-t; i > 1; i--)
		ans = (ans*i)%mod;
	printf("%lld", ans);
	return 0;
}
