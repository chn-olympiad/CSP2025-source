#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
const int M = 5e6 + 5;
const int mod = 1e9 + 7;
int n, q;
string s1[N], s2[N], ss[N];
//int ch[N][26], cnt[N], tot;
//void add(string s, int tp) {
//	int p = 0;
//	for (int i = 0; i < s.size(); i++) {
//		int c = s[i] - '0';
//		int &son = ch[p][c];
//		if (!son) son = ++tot;
//		p = son;
//		cnt[p]++;
//	}
//}
map<pair<int, int>, vector<int>> mp;
map<int, int> mp1;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		int len = s1[i].size();
		for (int j = 0; j < len; j++) {
			ss[i] += s1[i][j];
			ss[i] += s2[i][j];
		}
		int l = -1, r = -1;
		for (int j = 0; j < 2 * len; j += 2) {
			if (ss[i][j] != ss[i][j + 1] && l == -1) l = j;
			if (ss[i][j] != ss[i][j + 1]) r = j + 1;
		}
		int tmp = 0, tmp1 = 0, tmp2 = 0;
		for (int j = l; j <= r; j++) {
			tmp = (tmp * 256 % mod + ss[i][j]) % mod;
		}
		for (int j = l - 1; j >= 0; j--) {
			tmp1 = (tmp1 * 256 % mod + ss[i][j]) % mod;
		}
		for (int j = r + 1; j < 2 * len; j++) {
			tmp2 = (tmp2 * 256 % mod + ss[i][j]) % mod;
		}
//		cout << tmp << " " << tmp1 << " " << tmp2 << "\n";
		mp[{tmp, tmp1}].push_back(tmp2);
	}
	while (q--) {
		string st, ed;
		cin >> st >> ed;
		if (st.size() != ed.size()) {
			cout << 0 << "\n";
			continue;
		}
		int len = st.size();
		string s = "";
		for (int i = 0; i < len; i++) {
			s += st[i];
			s += ed[i];
		}
		int l = -1, r = -1;
		for (int i = 0; i < 2 * len; i += 2) {
			if (s[i] != s[i + 1] && l == -1) l = i;
			if (s[i] != s[i + 1]) r = i + 1;
		}
		int tmp = 0, tmp1 = 0, tmp2 = 0;
		for (int i = l; i <= r; i++) {
			tmp = (tmp * 256 % mod + s[i]) % mod;
		}
		mp1.clear();
		mp1[0] = 1;
		for (int i = r + 1; i < 2 * len; i++) {
			tmp2 = (tmp2 * 256 % mod + s[i]) % mod;
			mp1[tmp2] = 1;
		}
		int ans = 0;
		for (auto j : mp[{tmp, tmp1}]) {
			if (mp1[j]) ans++;
		}
		for (int i = l - 1; i >= 0; i--) {
			tmp1 = (tmp1 * 256 % mod + s[i]) % mod;
			for (auto j : mp[{tmp, tmp1}]) {
				if (mp1[j]) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

