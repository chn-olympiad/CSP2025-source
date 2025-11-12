#include <bits/stdc++.h>
namespace LIXUEAN{
	using std::cin ;
	using std::cout ;
	using std::endl ;
	typedef long long ll ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	const ll N = 5e5 + 5,K = (1ll << 20) + 5,AI = (1ll << 20) + 5 ;
	ll n,k,a[N],sum[N],dp[N],p[K] ;
	int Main(){
		std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
		freopen("xor.in","r",stdin),freopen("xor.out","w",stdout) ;
		cin >> n >> k ;
		For(i,1,n)cin >> a[i],sum[i] = sum[i - 1] ^ a[i] ;
		memset(p,0xff,sizeof(p)) ;
		p[0] = 0 ;
		For(i,1,n){
			dp[i] = std::max(dp[i - 1],p[k ^ sum[i]] + 1) ;
			p[sum[i]] = std::max(p[sum[i]],dp[i]) ;
		}
		cout << dp[n] ;
		return 0 ;
	}
} ;
int main(){
	LIXUEAN::Main() ;
	return 0 ;
}
