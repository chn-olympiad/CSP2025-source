#include <bits/stdc++.h>
using namespace std ;
int n , m ;

int A ( int n , int m ) {
	int sum = 1 ;
	for ( int i = n ; i > m ; i -- ) {
		sum *= i ; 
	}
	return sum ;
}

int C ( int n , int m ) {
	return A (n , m) / A(m,m) ;
	
}

int main ( ) {
	freopen ("employ.in" , "r" , stdin) ;
	freopen ("employ.out" , "w" , stdout) ;
	cin >> n >> m ;
	string s ;
//	cin >> n >> m ;
	cin >> s ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int x ;
		cin >> x ; 
	} 
	
	cout << C(n , m) ;
	
	return 0 ;
} 
