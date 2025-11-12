#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);

	int n,m;
	cin >> n >> m;

	vector<int> a;
	int a1;
	for( int i = 0 ; i < n * m ; i++ ){
		int mark;
		cin >> mark;
		
		if( i == 0 ){
			a1 = mark;
		}
		
		a.push_back( mark );
	}
	
	sort( a.begin() , a.end() );
	reverse( a.begin() , a.end() );
	
	int j = 1,k = 0;
	for( int i = 1 ; i <= n ; i++ ){
		for( j ; ( i & 1 == 1 ) ? j <= m : j >= 1 ; ( i & 1 == 1 ) ? j++ : j-- ){
			int t = a[ k++ ];
			
			if( t == a1 ){
				cout << i << " " <<j;
				return 0;
			}
		}
		
		j = ( i & 1 == 1 ) ? j - 1 : j + 1;
	}
	return 0;
} 
