#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

unordered_map <string, string> mp;

string s[N];

signed main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s1, s2;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		cin >> s2;
		mp[s[i]] = s2;
	}
	while (q --) {
		cin >> s1;
		cin >> s2;
		if (s1.length () != s2.length ()) {
			cout << 0 << '\n';
			continue;
		}
		int res = 0;
		for (int i = 1; i <= n; i ++ ) {
			string qwq = mp[s[i]];
			if (s1.find (s[i]) != string :: npos && s2.find (qwq) != string :: npos) {
				int t1 = s1.find (s[i]);
				int t2 = s2.find (qwq);
				if (t1 != t2) continue;
				int f = 1;
				for (int j = 0; j < t1; j ++) {
					if (s1[j] != s2[j]) {
						f = 0;
						break;
					}
				}
				if (!f) break;
				for (int j = t1 + s[i].length (); j < s1.length (); j ++) {
					if (s1[j] != s2[j]) {
						f = 0;
						break;
					}
				}
				res += f;
			}
		}
		cout << res << '\n';
	}
	return 0;
} 

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
*/
/*
Oh,I love ccf!I love dzd!I love the world!
*/
