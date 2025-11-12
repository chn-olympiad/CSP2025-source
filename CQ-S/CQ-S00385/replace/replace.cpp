#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, q, ans, l, r;
string s, t;
map<string, string> mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) cin >> s >> t, mp[s] = t;
	for (int i = 1; i <= q; i++) {
		cin >> s >> t, ans = l = 0, r = s.size() - 1;
		while (s[l] == t[l]) l++;
		while (s[r] == t[r]) r--;
		string x = "", y = "";
		for (int j = l; j <= r; j++) x += s[j], y += t[j];
		for (int j = l; j >= 0; j--) {
			if (mp[x] == y) ans++;
			string tx = x, ty = y;
			for (int k = r + 1; k < s.size(); k++) {
				x += s[k], y += t[k];
				if (mp[x] == y) ans++;
			}
			if (j != 0) x = s[j - 1] + tx, y = t[j - 1] + ty;
		}
		printf("%d\n", ans);
	}
	return 0;
}
