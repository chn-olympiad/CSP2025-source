#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 998244353;
ll n,a[5005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	
	ll ans = 0;
	for(ll st = 0;st < (1 << n);st++)
	{
		if(__builtin_popcount(st) < 3) continue;
		ll sum = 0,maxn = 0;
		for(ll p = st;p;p &= (p - 1))
		{
			int u = __builtin_ctz(p);
			sum += a[u],maxn = max(a[u],maxn);
		}
		if(sum > 2 * maxn)
			ans = (ans + 1) % mod;
	}
	cout << ans;
	return 0;
} 
