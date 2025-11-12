// T4 AC
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5005; 
const ll mod = 998244353;

ll n,a[N];

// Sub O(n ^ 2)
// It's OK
namespace Sub_On2
{
	ll cnt[N],maxn = 0;
	int Hack_cnt = 0;
	void solve()
	{
		for(int i = 1; i <= n; i++) maxn = max(maxn,a[i]);
		cnt[0] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = maxn; j >= a[i]; j--)
				cnt[j] = (cnt[j] + cnt[j - a[i]]) % mod/*,Hack_cnt++*/;
		for(int i = 1; i <= n; i++) cnt[a[i]]--; cnt[0] = 0;
		for(int i = 1; i <= maxn; i++) cnt[i] %= mod;
		for(int i = 1; i <= maxn; i++) cnt[i] = (cnt[i] + cnt[i - 1]) % mod;
		
		ll ans = 0,s2 = 1,Cn2 = 1;
		for(int i = 1; i <= n; i++) s2 = s2 * 2ll % mod;
		Cn2 = n * (n - 1) / 2;
		ans = (s2 - 1ll - Cn2 - n) % mod;
		for(int i = 1; i <= n; i++) ans = (ans - cnt[a[i]]) % mod;
		ans = (ans % mod + mod) % mod;
		printf("%lld\n",ans);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	
	Sub_On2::solve();
	return 0;
}
/*

Sub O(n^2):
let cnt[i] -> { \sum_S { sum(S) <= i } - cntnum[i] }
Ans = 2^n - 1 - n - C(n,2) - \sum{cnt[a[i]]} 

*/

