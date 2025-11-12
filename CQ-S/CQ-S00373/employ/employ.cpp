#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 20;
const ll Mod = 998244353;

ll f[1 << N][N];
ll ppc[1 << N];
char str[N];
ll arr[N],n,m;
void chadd(ll& x,ll y)
{
	x = (x + y) % Mod;
	return;
}
int main(void)
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(ll i = 1;i <= (1 << N) - 2;i++)
		ppc[i] = ppc[i >> 1] + (i & 1);
	scanf("%lld%lld",&n,&m);
	scanf("%s",str);
	for(ll i = 0;i < n;i++)
		scanf("%lld",arr + i);
	f[0][0] = 1;
	for(ll s = 0;s < (1 << n);s++)
	{
		ll r = ppc[s];
//		printf("ppc %lld : %lld\n",s,r);
		for(ll i = 0;i <= n;i++)
		{
//		printf("%lld %lld : %lld\n",s,i,f[s][i]);
			for(ll j = 0;j < n;j++)
				if(!(s >> j & 1))
				{
					chadd(f[s | (1 << j)][i + (i >= arr[j] || str[r] == '0')],f[s][i]);
				}
		}
	}
	ll ans = 0;
	for(ll i = 0;i <= n - m;i++)
		chadd(ans,f[(1 << n) - 1][i]);
	printf("%lld\n",(ans % Mod + Mod) % Mod);
	return 0;
}
/*
3 0
111
3 3 3

*/
