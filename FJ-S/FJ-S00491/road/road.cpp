#include <bits/stdc++.h>                                        
using namespace std;

int ui [1000005];
int vi [1000005];
int wi [1000005];
int cj [15];
int aji [1000005][15];

int main() {                                   
	freopen ( "road.in" , "r" , stdin );
	freopen ( "road.out" , "w" , stdout );
	
	int n , m , k;
	cin >> n >> m >> k;
	
	int a = 0 , b = 0 , d = 0;                             
	int a0 = 0 , b0 = 0;
	
	if (m == 2 || m == 1) {
		cin >> ui[1] >> vi[1] >> wi[1];
		a=wi[1];
	} else {
		for ( int i = 1 ; i <= m ; i++ ) {
			cin >> ui[i] >> vi[i] >> wi[i];
			a += wi[i];
		}
	}
	
	for ( int i = 1 ; i <= k ; i++ ) {
		cin >> cj[i];
		if ( cj[i] == 0 ) {
			a0++;
		}
		for ( int j = 1 ; j <= m ; j++ ) {
			cin >> aji[i][j];
			
			if ( aji[i][j] == 0 ) {
				b++;
			}
			d+=aji[i][j];
		}
		d+=cj[i];
		if ( b==0 ) {
			b = d;
		} else if ( b > d ) {
			b = d;
		}
		d = 0;
	}
	
	if ( a0 == k && b0 == m ) {
		cout <<0;
		return 0;
	} else if ( a > b ) {
		cout <<b;
		
	} else if ( b > a ) {
		cout <<a;
		
	} else {
		cout <<a;
		
	}
	          
	return 0;
}
