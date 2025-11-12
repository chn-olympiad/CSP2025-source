# include <bits/stdc++.h>
using namespace std ;
//using itn = long long ;
typedef long long itn ;
string s ;
itn s_size ;
char str [ 1000050 ] ;
itn str_size = 0 ;
bool cmp ( char x , char y ) {
	return x > y ;
}
void solve ( ) {
	cin >> s ;
	s_size = s.size ( ) ;
	for ( itn i = 0 ; i < s_size ; i ++ ) 
	{
		if ( s [ i ] >= '0' && s [ i ] <= '9' ) 
		{
			str [ ++ str_size ] = s [ i ] ;
		}
	}
//	for ( itn i = 0 ; i <= str_size ; i ++ ) 
//	{
//		cout << str [ i ] ;
//	}
	sort ( str + 0 , str + str_size + 1 , cmp ) ;
	for ( itn i = 0 ; i <= str_size ; i ++ ) 
	{
		cout << str [ i ] ;
	}
}
int main ( ) {
	freopen ( "number.in" , "r" , stdin ) ;
	freopen ( "number.out" , "w" , stdout ) ;
	solve ( ) ;
	return 0 ;
}