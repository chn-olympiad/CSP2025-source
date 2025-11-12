#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 200005
using namespace std ;
int n , q ;
map<string , string> mp ;
int main(){

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios :: sync_with_stdio(false) ;
	cin . tie(0) , cout . tie(0) ;
	
	cin >> n >> q ;
	for(int i = 1 ; i <= n ; i++) {
		string a , b ;
		cin >> a >> b ;
		mp[a] = b ;
	}
	while(q --) {
		int ans = 0 ;
		string a , b , x = "" , y = "" , z = "" ;
		cin >> a >> b ;
		if(mp . count(a)) {
			if(mp[a] == b)ans ++ ;
		}
		if(a == b)ans ++ ;
		for(int i = 0 ; i < a . size() ; i++) {
			x += a[i] ;
			for(int j = a . size() - 1 ; j > i ; j --) {
				y = "" ;
				for(int k = i + 1 ; k < j ; k++) {
					y = y + a[i] ;
				}
				z = "" ;
				for(int k = j ; k <= a . size() - 1 ; k++) {
					z += a[k] ;
				}
				if(mp . count(y)) {
					string tmp = x + y + z ;
					if(tmp == b) {
						ans ++ ;
					}
				}
				
			}
		}
		cout << ans << endl ;
	}
	return 0 ;

}

