# include <bits/stdc++.h>
# define N (1000002)
using namespace std;

int a[N];
int tot;
string s;
int main( ) {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	for ( int i = 0; i < int(s.size()); ++i ) {
		if ( s[i] >= '0' && s[i] <= '9' ) a[++tot] = int( s[i] - '0' );
	}
	
	sort( a + 1, a + tot + 1 );
	
	for ( int i = tot; i >= 1; --i ) cout << a[i];
	
	return 0;
	
} //9£º00  
