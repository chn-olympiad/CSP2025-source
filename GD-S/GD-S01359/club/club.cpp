#include <bits/stdc++.h>
namespace LIXUEAN{
	using std::cin ;
	using std::cout ;
	using std::endl ;
	using std::vector ;
	using std::sort ;
	typedef long long ll ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	const ll T = 5 + 5,N = 1e5 + 5,COMPANY = 3 + 1,oo = 1e13 ;
	struct node{ ll comp,w ; } a[N][COMPANY] ;
	ll t,n,ans,maxx_id ;
	vector<ll> company[COMPANY] ;
	ll myMin(const node p[]){
		ll res = oo,maxx_val = 0 ;
		For(i,1,3)if(p[i].comp == maxx_id)
			maxx_val = p[i].w ;
		For(i,1,3)if(p[i].comp != maxx_id)
			res = std::min(res,maxx_val - p[i].w) ;
		return res ;
	}
	bool cmpW(node a,node b){
		return a.w > b.w ;
	}
	bool cmp(ll t1,ll t2){
		return myMin(a[t1]) < myMin(a[t2]) ;
	}
	int Main(){
		std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
		freopen("club.in","r",stdin),freopen("club.out","w",stdout) ;
		cin >> t ;
		while(t --){
			cin >> n ;
			For(i,1,3)vector<ll>().swap(company[i]) ;
			ans = 0 ;
			For(i,1,n){
				ll want = 0 ;
				For(o,1,3)
					cin >> want,a[i][o] = node{o,want} ;
				sort(a[i] + 1,a[i] + 3 + 1,cmpW) ;
				company[a[i][1].comp].push_back(i) ;
				ans += a[i][1].w ;
			}
			maxx_id = 1 ;
			For(i,2,3)
				if(company[i].size() > company[maxx_id].size())
					maxx_id = i ;
			if(company[maxx_id].size() <= n / 2){ cout << ans << '\n' ; continue ; }
			std::sort(company[maxx_id].begin(),company[maxx_id].end(),cmp) ;
			RFor(i,company[maxx_id].size() - n / 2 - 1,0)
				ans -= myMin(a[company[maxx_id][i]]) ;
			cout << ans << '\n' ;
		}
		return 0 ;
	}
} ;
int main(){
	LIXUEAN::Main() ;
	return 0 ;
}
