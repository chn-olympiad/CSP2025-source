#include <bits/stdc++.h>
using namespace std ;

long long n , m , a[502] , cnt , ans = 1 ;
string s ;

int main()
{
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout) ;
	cin >> n >> m ; 
	cin >> s ;
	cnt = n ;
	for( int i = 1 ; i<= n ; i ++ )
	{
		cin >> a[i] ;
		if(a[i] == 0) cnt -- ;
	}
	for( int i = 1 ; i <= cnt ; i ++ )
	{
		ans = (ans * i) % 998244353 ;
	}
	cout << ans ;
	return 0 ;
} 
