#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int n, q;
string s[200005][2];
map <string, int> ls;
set <pair <int, int> > S; 
int tot;
string t[2];
string c, cc;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= n; i++) {
		if (!ls.count(s[i][0])) ls[s[i][0]] = ++tot;
		if (!ls.count(s[i][1])) ls[s[i][1]] = ++tot;
		S.insert(make_pair(ls[s[i][0]], ls[s[i][1]]));
	}
	
	while (q--) {
		cin >> t[0] >> t[1];
		if (t[0].length() != t[1].length()) {
			cout << 0 << endl;
			continue;
		}
		int len = t[0].length();
		t[0] = " " + t[0];
		t[1] = " " + t[1];
		int l = 1, r = len;
		for (int i = 1; i <= len; i++) {
			if (t[0][i] != t[1][i]) {
				l = i;
				break;
			}
		}
		for (int i = len; i >= 1; i--) {
			if (t[0][i] != t[1][i]) {
				r = i;
				break;
			}
		}
		
		int ans = 0;
		for (int L = 1; L <= l; L++) {
			for (int R = r; R <= len; R++) {
				c = "";
				cc = "";
				for (int i = L; i <= R; i++) {
					c += t[0][i];
					cc += t[1][i];
				}
				if (ls.count(c) && ls.count(cc)) {
					int lsc = ls[c], lscc = ls[cc];
					if (S.count(make_pair(lsc, lscc))) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
} 
