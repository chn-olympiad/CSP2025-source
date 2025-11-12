#include<bits/stdc++.h>
using namespace std;

string szr( int a ) {
	string str = "";
	while( a >= 1 ) {
		str += a % 2 + '0';
		a /= 2;
	}
	for( int i = 0; i < str.size() / 2; i++ ) {
		swap( str[i], str[str.size()-i-1] );
	}
	return str;
}

int xx( int a, int b ) {
	int ans = 0;
	string stra = szr( a ), strb = szr( b );
	int ml = max( stra.size(), strb.size() );
	int nl = min( stra.size(), strb.size() );
	string wry;
	char c, d;
	for( int i = 0; i < ml; i++ ) {
		if( i < nl ) {
			c = stra[i], d = strb[i];
		}else{
			if( stra.size() == nl ) {
				c = '0';
			}
			if( strb.size() == nl ) {
				d = '0';
			}
		}
		if( c != d ) {
			wry += '1';
		}else{
			wry += '0';
		}
	}
	cout << "{" << wry << "}";
	for( int i = 0; i < wry.size(); i++ ) {
		if( wry[i] == '1' ) {
			ans += pow( 2, i );
		}
	}
	return ans;
}

int main() {
//	freopen( "xor.in", "r", stdin );
//	freopen( "xor.out", "w", stdout );
	int a, b;
	cin >> a >> b;
	cout << szr( a ) << ' ' << szr( b );
	cout << xx( a, b );
	return 0;
} 
