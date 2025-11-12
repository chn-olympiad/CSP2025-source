#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 5e5 + 5 ; ;

int n ;
int a[N] ;
int ans ;

signed main () {
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	
	freopen("polygon.in" , "r" , stdin) ;
	freopen("polygon.out" , "w" , stdout) ;
	
	cin >> n ;
	
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i] ;
	}
	
	sort (a + 1 , a + n + 1) ;
	
	if (n >= 3) {
		for (int i = 1 ; i <= n ; i ++) {
			for (int j = i + 1 ; j <= n ; j ++) {
				for (int k = j + 1 ; k <= n ; k ++) {
					if (max({a[i] , a[j] , a[k]}) * 2 < a[i] + a[j] + a[k]) {
						ans ++ ;
						ans %= 998244353 ;
					}
				}
			}
		}
		cout << ans ;
	}
	else if (n < 3) {
		cout << 0 ;
    }
	else {
		cout << 1 ;
	}
	
	return 0 ;
	
}