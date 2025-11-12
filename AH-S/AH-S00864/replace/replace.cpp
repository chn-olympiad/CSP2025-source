#include <bits/stdc++.h>
using namespace std;

int n, q;
map<string, map<string, int> > mp;

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		mp[t1][t2]++;
	}
	while(q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.length() != t2.length()) {
			cout << 0 << endl;
			continue;
		}
		int l, r;
		for(int i = 0; i < t1.length(); i++)
			if(t1[i] != t2[i]) {l = i - 1; break; }
		for(int i = t1.length() - 1; i >= 0; i--)
			if(t1[i] != t2[i]) {r = i + 1; break; }
		int ans = 0;
		for(int i = 0; i <= l + 1; i++)
			for(int j = r - 1; j < t1.length(); j++) {
				string s1 = t1.substr(i, j - i + 1);
				string s2 = t2.substr(i, j - i + 1);
				//cout << i << " " << j << " " << s1 << " " << s2 << endl;
				ans += mp[s1][s2];
			}
		cout << ans << endl;
	}
	return 0;
}
/*
 * I hate you, CCF
 * AFO */
