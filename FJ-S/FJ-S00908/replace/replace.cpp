/* CSP2025 RP++ 
yuji 20 */
#include <bits/stdc++.h> 
using namespace std;
string t[(int)2e5 + 50][2], s, s1;
int main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout); 
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> t[i][0] >> t[i][1];
	while (q--) {
		cin >> s >> s1;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < s.length(); ++j) {
				string ns = s;
				for (int k = 0, k2 = j; k < t[i][0].length(); ++k, ++k2)
				    if (ns[k2] == t[i][0][k]) ns[k2] = t[i][1][k];
				    else goto NXT;
				if (ns == s1) ++ans;
				NXT:; 
			}
		} cout << ans << '\n'; 
	}
}
/*
zong ji 100 + 64 + 20 + 8 = 192
*/
