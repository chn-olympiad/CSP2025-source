#include<bits/stdc++.h>
using namespace std;
string a, b;
int main() {
	freopen( "number.in", "r", stdin );
	freopen( "number.out", "w", stdout );
	cin >> a;
	for ( char i : a )
		if ( isdigit( i ) )
			b.push_back( i );
	sort( b.begin(), b.end(), greater<>() );
	cout << b;
	return 0;
}
