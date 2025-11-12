#include <bits/stdc++.h>
namespace LIXUEAN{
	using std::cin ;
	using std::cout ;
	using std::endl ;
	typedef long long ll ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	const ll N = 1e1 + 5,M = 1e1 + 5,AI = 1e2 + 5 ;
	ll n,m,val,a[N * M] ;
	int Main(){
		std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
		freopen("seat.in","r",stdin),freopen("seat.out","w",stdout) ;
		cin >> n >> m ;
		For(i,1,n * m)cin >> a[i] ;
		val = a[1] ;
		std::sort(a + 1,a + n * m + 1,std::greater<ll>()) ;
		ll p = std::lower_bound(a + 1,a + n * m + 1,val,std::greater<ll>()) - a ;
		ll col = (p - 1) / n + 1,row = 0 ;
		if(col & 1)row = p - (col - 1) * n ;
		else row = n - (p - (col - 1) * n) + 1 ;
		cout << col << ' ' << row ;
		return 0 ;
	}
} ;
int main(){
	LIXUEAN::Main() ;
	return 0 ;
}
