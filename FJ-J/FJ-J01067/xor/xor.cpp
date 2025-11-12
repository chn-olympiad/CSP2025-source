# include <bits/stdc++.h>
# define N (200002)
using namespace std;

int n, k, ans, a[N];
bool flag = true;

int main( ) {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for ( int i = 1; i <= n; ++i ) {
		cin >> a[i];
		if ( a[i] != 1 ) flag = false;
	}
	
	if ( flag ) {
		cout << floor( ( n * 1.0 ) / 2 );
		return 0;
	} else {
		if ( k == 0 ) {
			for ( int i = 1; i <= n; ++i ) {
				if ( a[i] == 0 ) ans++;
				else {
					if ( a[ i + 1 ] == 1 ) ans++, i++;
				}
			}
		}	//B中分类讨论 
		if ( k == 1 ) {
			for ( int i = 1; i <= n; ++i ) {
				if ( a[i] == 1 ) ans++;
				else {
					if ( a[ i + 1 ] == 1 ) ans++, i++;
				}
			}
		}
		cout << ans;
		return 0;
	}	// 特殊性质B 
	
	return 0;
	
}
