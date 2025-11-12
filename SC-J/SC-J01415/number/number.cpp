#include<bits/stdc++.h>
using namespace std ;
int main() {
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	int num[15]={} ;
	char key ;
	bool zero=1 ;
	while ( cin>> key ) {
		if ( '0'<=key && key<='9' ) {
			num[key-'0']++ ;
			if ( key!='0' ) zero=0 ;
		}
	}
	if ( zero ) cout<< "0" ;
	else {
		for ( int i=9 ; i>=0 ; i-- ) {
			for ( int j=1 ; j<=num[i] ; j++ ) {
				cout<< i ;
			}
		}
	}
	return 0 ;
}
/*
吾日三省吾身：开 long long 了乎？ freopen注释了乎？ MLE了乎？ 
*/