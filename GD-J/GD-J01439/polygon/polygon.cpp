#include <bits/stdc++.h>
using namespace std;

long long n, k = 0, l = 0, maxa = 0;
long long a[1000000000000];

int main(){
	
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	fin >> n;
	for( int i = 1; i <= n; ++ i ){
		fin >> a[ i ];
	}
	if( n < 3 ){
		fout << 0;
	}else if( n == 3 ){
		if( a[ 1 ] + a[ 2 ] > a[ 3 ] ){
			++ k;
		}
		if( a[ 2 ] + a[ 3 ] > a[ 1 ] ){
			++ k;
		}
		if( a[ 1 ] + a[ 3 ] > a[ 2 ] ){
			++ k;
		}
		fout << k;
	}else if( n > 3 ){
		for( int j = 0; j < n; ++ j ){
			for( int i = 1; i <= n - j; ++ i ){
				l += a[ i ];
				if( a[ i ] > maxa ){
					maxa = a[ i ];
				}
			}
			maxa *= 2;
			if( l > maxa ){
				++ k;
			}
			k %= 998244353;
		}
		fout << k;
	} 
	fin.close();
	fout.close();
	
	return 0;
	
} 
