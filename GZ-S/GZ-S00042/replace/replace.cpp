//GZ-S00042 贵阳市第一中学 刘信果
#include <bits/stdc++.h>
#define ull unsigned long long 
#define int long long
using namespace std;

const int N = 2e5+5;
int n, q, ans;
string t1[N], t2[N];
map<string, map<string, int>> cnt;

string getstr(string str, int l, int r) {
	string res = "";
	for (int i = l; i <= r; ++i)
		res += str[i];
	return res;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		string s1, s2; cin >> s1 >> s2;
		if (s1 == s2) continue;
		cnt[s1][s2]++;
	}
	for (int i = 1; i <= q; ++i) {
		string s1, s2; cin >> s1 >> s2;
		if (s1.size() != s2.size()) {
			cout << 0 << endl;
			continue;
		}
		int l = 0, r = s1.size()-1;
		while (s1[l] == s2[l]) l++;
		while (s1[r] == s2[r]) r--;
		ans = 0;
		string t1, t2;
		for (int i = 0; i <= l; ++i) {
			t1 = getstr(s1, i, r-1);
			t2 = getstr(s2, i, r-1);
			for (int j = r; j < s1.size(); ++j) {
				t1 += s1[j], t2 += s2[j];
				ans += cnt[t1][t2];
			}
		}
		cout << ans << endl;
	}
	return 0; 
}
