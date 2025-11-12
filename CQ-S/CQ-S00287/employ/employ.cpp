#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
string s;
int c[505];
int p[505];
int ans;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> c[i];
		p[i] = i;
	}
	do{
		int diened = 0;
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( s[i] == '0' ) {
				diened ++;
			} else if ( diened >= c[p[i]] ) {
				diened ++;
			}
		}
		if ( n - diened >= m ) {
			ans ++;
//			for ( int i = 1 ; i <= n ; i ++ ) {
//				cout << p[i] << " ";
//			}
//			cout << diened ;
//			cout << endl;
		}
	}while(next_permutation(p+1,p+1+n));
	cout << ans << endl;
}
