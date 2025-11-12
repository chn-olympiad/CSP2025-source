//GZ-S00219   ¿Ó≈‡Íª ±ı∫˛÷–—ß
#include <bits/stdc++.h>
using namespace std;

long long n , m ;
string s ;
bool f ;
long long ans = 1 ;
long long sum ;
long long sum2 ;
int c[100005] ;

int main() {
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);


	cin >> n >> m ;

	cin >> s ;
	for( int i = 0 ; i <= s.size() - 1 ; i++ ) {
		if( s[i] != '1' ) {
			f = true ;
		}
		if( f != true ){
			sum2++ ;
		}
		if( s[i] == '1' ) {
			sum++ ;
			sum %= 998244353 ;
		}
	}
	
	for( int i = 1 ; i <= n ; i++ ){
		cin >> c[i] ;
	} 

	if( f == false ) {
		for( int i = 1 ; i <= n ; i++ ) {
			ans *= i ;
			ans %= 998244353 ;
		}
		cout << ans % 998244353 ;
		return 0 ;
	}
	
	return 0 ;

}

