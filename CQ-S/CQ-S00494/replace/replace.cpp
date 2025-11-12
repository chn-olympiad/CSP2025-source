#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, q;

string s1[N];
string s2[N];
unordered_map<string, int> mp;

int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		mp[s1[i]] = i;
	}
	if (n <= 100) {
		while (q--) {
			int ans = 0;
			string u, v;
			cin >> u >> v;
			for (int i = 0; i < u.size(); ++i) {
				string str = "";
				for (int j = i; j < u.size(); ++j) {
					str += u[j];
					if (mp[str]) {
						string ts = u;
						ts.erase (i, str.size());
						ts.insert (i, s2[mp[str]]);
						if (ts == v) 
							++ans;
					}					
				}
			}
			cout << ans << '\n';
		}
	}
	else {
		while (q--) {
			string u, v;
			cin >> u >> v;
			cout << 0 << '\n';
		}
	}
	return 0;
}

/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
