#include<bits/stdc++.h>
using namespace std;
int n, q;
map<string, string> mp;
string s, t;
string gets(int l, int r) {
	string x;
	for (int i = l; i <= r; i++)
		x += s[i];
	return x;
}
string gett(int l, int r) {
	string x;
	for (int i = l; i <= r; i++)
		x += t[i];
	return x;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s >> t;
		mp[s] = t;
	}
	while (q--) {
		int ans = 0;
		cin >> s >> t;
		int len = s.size();
		for (int l = 0; l < len; l++) {
			for (int r = l + 1; r < len; r++) {
				if (mp[gets(l, r)] == gett(l, r) && gets(0, l - 1) == gett(0, l - 1) && gets(r + 1, len - 1) == gett(r + 1, len - 1))
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}