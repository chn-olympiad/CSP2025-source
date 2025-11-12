#include<bits/stdc++.h>
using namespace std;
int c,r,y,o ;
int a[114514] ;
int b[114514] ;
void shuru(){
	cin >> c >> r ;
	y = c * r ;
	o = a[1] ;
	for( int i = 0 ; i < y ; i++ ){
		cin >> a[i] ;
	}
	sort( a , y + a ) ;
}
void fanzhuan(){
	int k = 0 ;
	for( int i = y ; i >= 0 ; i-- ){
		b[k] = a[i] ;
		k++ ;
	}
	for( int i = 0 ; i < y ; i++ ){
		cout << b[i] << " " ;
	}
}
int jisuan(int x , int z ){
	if( 
	for( int i = 0 ; i < y ; i++ ){

	}	
}
int main(){
	freopen( "seat.in" , r , stdin );
	freopen( "seat.out" , w , stdout ) ;
	cout << c << " " r << endl;
	return 0 ;
}
