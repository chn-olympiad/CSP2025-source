#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n, q, ss, ts, ans;
string t1, t2;
string s1[N], s2[N];
bool f;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for ( int i = 1; i <= n; i++ ) {
		cin >> s1[i] >> s2[i];
	}
	while ( q-- ) {
		cin >> t1 >> t2;
		ans = 0;
		for ( int i = 1; i <= n; i++ ) {
			ss = s1[i].size();
			ts = t1.size();
			for ( int j = 0, k = 0; j < ts; j++, k++ ) {
				if ( !( s1[i][k] == t1[j] ) || !( s2[i][k] == t2[j] ) ) {
					j -= k;
					k = -1;
					if ( t1[j] != t2[j] ) break;
					continue;
				}
				if ( k == ss - 1 ) {
					for ( int l = j + 1; l < ts; l++ ) {
						if ( t1[l] != t2[l] ) f = 1;
					}
					if ( !f ) ans++;
					f = 0;
					j -= k;
					k = -1;
					if ( t1[j] != t2[j] ) break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
