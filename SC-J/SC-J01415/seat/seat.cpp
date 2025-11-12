#include<bits/stdc++.h>
using namespace std ;
const int N=110 ;
int a[N] , n , m , s ;
bool cmp( int a , int b ) {
	return a>b ;
} 
int main() {
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	cin>> n >> m ;//n行m列
	s=n*m ;
	for ( int i=1 ; i<=s ; i++ ) {
		cin>> a[i] ;
	}
	int my=a[1] ;
	sort(a+1,a+1+s,cmp) ;
//	for ( int i=1 ; i<=s ; i++ ) {
//		cout<< a[i] << " " ;
//	}
	int x=0 , y=1 , i=0 ;
	while ( i<s ) {
		while ( x<n ) {
			i++ ;
			x++ ;
			if ( a[i]==my ) {
				cout<< y << " " << x ;
				return 0 ;
			}
//			cout<< y << " " << x << endl ;
		}
		y++ ;
		x=n+1 ;
		while ( x>1 ) {
			i++ ;
			x-- ;
			if ( a[i]==my ) {
				cout<< y << " " << x ;
				return 0 ;
			}
//			cout<< y << " " << x << endl ;
		}
		y++ ;
		x=0 ;
	}
	return 0 ;
}
/*
2 2
99 100 97 98
3 3
94 95 96 97 98 99 100 93 92
2 2
98 99 100 97
*/