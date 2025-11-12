#include <bits/stdc++.h>
using namespace std;

int n, m;
int h;
int g=1;

int main () {
	freopen( "seat.in" ,"r" ,stdin );
	freopen( "seat.out" ,"w" ,stdout );
	cin >> n >> m;
	cin >> h;
	for ( int i=2;i<=n*m;i++ ) {
		int f;
		cin >> f;
		if ( f > h ) g++;
		 
	}
	int r = ( g*3 )/4;
	cout << h; 
	return 0;
} 
