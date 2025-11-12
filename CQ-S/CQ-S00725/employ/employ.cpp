#include<bits/stdc++.h>
using namespace std;
int n, m, f, cnt, s[505], c[505];
long long ans = 1;
string t;
int main() {
	freopen( "replace.in", "r", stdin );
	freopen( "replace.out", "w", stdout );
	cin >> n >> m >> t;
	for ( int i = 0; i < n; i++ ) cin >> c[i];
	sort( c, c + n );
	s[0] = 0;
	for ( int i = 1; i < t.size(); i++ ) {
		if ( cnt == m ) cnt = i + 1;
		if ( t[i - 1] == '1' ) cnt++, s[i] = s[i - 1];
		else s[i] = s[i - 1] + 1;
	}
	for ( int i = 0; i < cnt; i++ ) {
		if ( c[i] > s[i] ) {
			ans *= n - i - 1;
		}
	}
	cout << ans % 998244353;
	fclose( stdin );
	fclose( stdout );
	return 0;
}
