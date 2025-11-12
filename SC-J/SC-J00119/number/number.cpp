#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n"
const int N = 1e6 + 5 ;

string s ;
int a[N] ;
int sum ;
string ans ;

signed main () {
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
	
	cin >> s ;
	
	for (int i = 0 ; i < s.size() ; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[sum] = s[i] - '0' ;
//			cout << a[sum] << " " << sum << endl ;
			sum ++ ;
		}
	}
	
	sort(a , a + sum) ;
	
	for (int i = sum - 1 ; i >= 0 ; i --) {
		ans += a[i] + '0' ;
	}
	
	cout << ans ;
	
	return 0 ;
	
}