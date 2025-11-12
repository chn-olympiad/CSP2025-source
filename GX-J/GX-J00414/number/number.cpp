#include<bits/stdc++.h>
using namespace std;
char a[1000000] ;
int b[114514114514114514114514114514] ;
int n = 0 ;
void shuru(){
	cin >> a ;
	int len = strlen(a) ;
	for( int i = 0 ; i < len ; i++ ){
		char u = a[i] ;
		if( u <= '9' and u >= '0' ){
			b[n] = u - '0' ;
			n++ ;
		}
	}
}
void jisuan(){
	sort( b , b + n );
	for( int i = n-1 ; i >= 0 ; i-- ){
		cout << b[i] ;
	}
	cout << endl;
}
int main(){
	freopen( "number.in" , r , stdin ) ;
	freopen( "number.out" , w , stdout );
	shuru() ;
	jisuan() ;
	return 0 ;
}
