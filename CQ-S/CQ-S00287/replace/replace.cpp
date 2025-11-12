#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
string s[200005], t[200005];

string u, v;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> s[i] >> t[i];
	}
	while (m -- ){
		int ans = 0;
		
		 cin >> u >> v;
		 u = " " + u;
		 v = " " + v;
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( i + s[i].size() <= n ) {
				if ( u.substr(i, i+s[i].size()) == s[i] ) 
				if ( u.substr(1, i-1) + t[i] + u.substr(i+s[i].size(), n-i+1) == v ) {
					ans ++;
				}
			}
		} 
		cout << ans << endl;
	}
}
