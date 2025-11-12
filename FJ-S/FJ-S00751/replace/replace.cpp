#include <bits/stdc++.h>
using namespace std;

int n, q;
struct ss {
	string s1, s2;
	int len;
} s[200005];

inline bool isSub(string fa, string son, int begin, string s2, string t2) {
	int sonl = son.length();
	if (fa.length() - begin < sonl) return false;
	return fa.substr(begin, sonl) == son && s2 == t2.substr(begin, sonl);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> s[i].s1 >> s[i].s2;
		s[i].len = s[i].s1.length();
	}
	for (int T=1; T<=q; T++) {
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.length(), maxpref = 0, maxsuf = 0;
		for (int k=0; k<len; k++) {
			if (t1[k] == t2[k]) maxpref++;
			else break;
		}
		for (int k=len-1; k>=0; k--) {
			if (t1[k] == t2[k]) maxsuf++;
			else break;
		}
		for (int i=1; i<=n; i++) {
			for (int j=max(len-maxsuf-s[i].len, 0); j<=maxpref; j++) {
				if (isSub(t1, s[i].s1, j, s[i].s2, t2)) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
