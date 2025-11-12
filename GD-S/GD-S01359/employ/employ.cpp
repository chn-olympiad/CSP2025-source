#include <bits/stdc++.h>
namespace LIXUEAN{
	using std::cin ;
	using std::cout ;
	using std::endl ;
	using std::vector ;
	using std::string ;
	typedef long long ll ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	const ll N = 5e2 + 5,M = N,mod = 998244353 ;
	ll n,m,c[N] ;
	string s ;
	bool all_passed = true ;
	void solve1() ;
	void solve2() ;
	int Main(){
		std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
		freopen("employ.in","r",stdin),freopen("employ.out","w",stdout) ;
		cin >> n >> m >> s,s = ' ' + s ;
		For(i,1,n)s[i] -= '0',all_passed &= s[i] ;
		For(i,1,n)cin >> c[i] ;
		//if(all_passed)solve1() ;
		//else 
			solve2() ;
		return 0 ;
	}
	void solve1(){
		ll ans = 1,cnt = 0 ;
		For(i,1,n)if(c[i] != 0)++ cnt ;
		if(cnt < m){ cout << 0 ; return ; }
		For(i,1,n)
			ans = ans * i % mod ;
		cout << ans ;
		return ;
	}
	void solve2(){
		ll ans = 0,tms = 1 ;
		vector<ll> turn ;
		For(i,1,n)turn.push_back(i),tms *= i ;
		while(tms --){
			ll failed = 0 ;
			For(i,0,n - 1)
				if(!s[i + 1] || failed >= c[turn[i]])++ failed ;
			if(n - failed >= m)
				ans = (ans + 1) % mod ;
			next_permutation(turn.begin(),turn.end()) ;
		}
		cout << ans ;
		return ;
	}
} ;
int main(){
	LIXUEAN::Main() ;
	return 0 ;
}
