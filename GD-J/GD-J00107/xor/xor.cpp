#include<bits/stdc++.h>
using namespace std;
int n[ 500005 ];
int s , k , ans;
int check( int x , int y ){
	if( x == y ){
		return n[ x ];
	}
	int c = n[ x ] xor n[ x + 1 ];
	for( int i = x + 2 ; i <= y ; i++ ){
		c = c xor n[ i ];
	}
	return c;
}
int check1( int y , int x ){
	if( x == y ){
		return n[ x ];
	}
	int c = n[ x ] xor n[ x - 1 ];
	for( int i = x - 2 ; i >= y ; i-- ){
		c = c xor n[ i ];
	}
	return c;
}
int main(){
	freopen( "xor.in" , "r" , stdin );
	freopen( "xor.out" , "w" , stdout );
	cin >> s >> k;
	for( int i = 1 ; i <= s ; i++ ){
		cin >> n[ i ];
	}
	for( int i = 1 , j = 1 ; i <= s ; ){
		if( check( i , j ) == k ){
//			cout << " i == " << i << endl;
//			cout << " j == " << j << endl;
			ans++;
			i = j + 1;
			j = i - 1;
		}
		else{
			if( j >= s ){
				i++;
				j = i - 1;
			}
		}
		j++;
	}
	int ans1 = 0;
	for( int i = s , j = s ; i >= 1 ; ){
		if( check1( i , j ) == k ){
//			cout << " i == " << i << endl;
//			cout << " j == " << j << endl;
			ans1++;
			i = j - 1;
			j = i + 1;
		}
		else{
			if( j <= 1 ){
				i--;
				j = i + 1;
			}
		}
		j--;
	}
	cout << max( ans1 , ans );
	return 0;
}
