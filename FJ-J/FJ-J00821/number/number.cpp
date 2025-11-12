#include<bits/stdc++.h>
using namespace std;

int arr[20];
string str;

int main() {
	freopen( "number.in", "r", stdin );
	freopen( "number.out", "w", stdout );
	
	cin >> str;
	for( int i = 0; i < int( str.size() ); i++ ) {
		if( isdigit( str[i] ) ) arr[ int(str[i]-'0') ] ++;
	}
	for( int i = 9; i >= 0; i-- ) {
		while( arr[i] ) {
			cout << i;
			arr[i]--;
		}
	}
	
	return 0;
} 
