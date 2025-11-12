#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 505 
using namespace std ;
int n , a[N] , m , cnt ;
string s ;
long long ans = 1 ;
const int mod = 998244353 ;
bool type = true ;
int main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios :: sync_with_stdio(false) ;
	cin . tie(0) , cout . tie(0) ;
	
	cin >> n >> m >> s ;
	for(int i = 0 ; i < n ; i++) {
		if(s[i] != '1')type = false , cnt ++ ;
	}
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
	}
	for(int i = 1 ; i <= n ; i++) {
		ans = (ans * i) % mod ;
	}
	
	if(type)cout << ans ;
	else if(cnt < m) {
		cout << 0 ;
		return 0 ;	
	}
	else if(m == 1) {
		cout << ans ;	
	}
	
	return 0 ;

}

