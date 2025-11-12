#include <bits/stdc++.h>
namespace LIXUEAN{
	using std::cin ;
	using std::cout ;
	using std::endl ;
	using std::string ;
	typedef long long ll ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	const ll N = 1e6 + 5 ;
	ll a[10] ;
	string s ;
	int Main(){
		std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
		freopen("number.in","r",stdin),freopen("number.out","w",stdout) ;
		cin >> s ;
		for(auto it : s)
			if(it >= '0' && it <= '9')
				++ a[it - '0'] ;
		RFor(i,9,0)
			while(a[i])cout << char(i + '0'),-- a[i] ;
		return 0 ;
	}
} ;
int main(){
	LIXUEAN::Main() ;
	return 0 ;
}
