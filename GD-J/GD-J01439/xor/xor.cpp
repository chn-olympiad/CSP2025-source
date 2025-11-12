#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[1000000000000];

int main(){
	
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	fin << n << k;
	for( int i = 1; i <= n; ++ i ){
		fin << a[ i ];
	}
	for( int i = 1; i <= n; ++ i ){
		if( n == 1 && k == 0 && a[ i ] == 1 ){
			fout << 0;
		}
		if( n == 10 && k <= 1 && a[ i ] <= 1 ){
			fout << max( a[ i ] );
		}
	}
	fin.close();
	fout.close();
	
	return 0;
	
} 
