#include<bits/stdc++.h>
using namespace std;
int sum = 1 , x , y , a , b;
int main(){
	freopen( "seat.in" , "r" , stdin );
	freopen( "seat.out" , "w" , stdout );
	cin >> x >> y >> a ;
	for( int i = 1 ; i < x * y ; i++ ){
		cin >> b;
		if( b > a ){
			sum++;
		}
	}
	if( sum <= x ){
		cout << "1" << " " << sum;
		return 0;
	}
	int n , m;
	n = sum / x;
	if( sum % x > 0 ){
		n++;
	}
	if( n % 2 == 0 ){
		m = x - ( sum % x - 1 );
		if( sum % x == 0 ){
			m = 1;
		}
		cout << n << " " << m;
	}
	else{
		m = sum % x;
		if( sum % x == 0 ){
			m = 4;
		}
		cout << n << " " << m ;
	}
	return 0;
}
