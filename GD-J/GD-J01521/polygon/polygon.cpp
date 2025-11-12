#include <bits/stdc++.h>
namespace LIXUEAN{
	using std::cin ;
	using std::cout ;
	using std::endl ;
	typedef long long ll ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	const ll N = 5e3 + 5,MAXAI = 5e3 + 5,mod = 998244353 ;
	ll n,a[N],dp[MAXAI],maxx,ans,pow2[N] ;
	int Main(){
		std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
		freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout) ;
		pow2[0] = 1 ;
		For(i,1,N - 1)pow2[i] = pow2[i - 1] * 2 % mod ;
		cin >> n ;
		For(i,1,n)cin >> a[i] ;
		std::sort(a + 1,a + n + 1),maxx = a[n] ;
		dp[0] = 1 ;
		For(i,1,n){
			if(i >= 3){
				ans = (ans + pow2[i - 1]) % mod ;
				For(o,0,a[i])
					ans = (ans - dp[o] + mod) % mod ;
			}
			RFor(o,maxx,a[i])
				dp[o] = (dp[o] + dp[o - a[i]]) % mod ;
		}
		cout << ans ;
		return 0 ;
	}
} ;
int main(){
	LIXUEAN::Main() ;
	return 0 ;
}
