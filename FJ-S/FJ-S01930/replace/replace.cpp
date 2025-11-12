#include <bits/stdc++.h>
using namespace std;
using ui128 = unsigned __int128;
using PUU = pair<ui128, ui128>;
const int BASE = 29;
ui128 hsh(const string &s) {
	ui128 ret = 0;
	for (char i : s) {
		ret = ret * BASE + (i - 'a' + 1);
	}
	return ret;
}
ui128 qpow(ui128 a, int b) {
	ui128 ret = 1;
	while (b) {
		if (b & 1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
ui128 hsh1(int l, int r, const vector<ui128> &mp) {
	return mp[r] - mp[l - 1] * qpow(BASE, l - 1);
}
const int N = 1e6 + 10;
ui128 frac[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;

	bool flag = true;
	map<int, vector<pair<int, int>>>mp;
	map<ui128, map<ui128, int>> s;
	for (int i = 1; i <= n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		int b1, b2;
		for (auto ch : s1) {
			if (ch != 'a' && ch != 'b') flag = false;
		}

		for (auto ch : s2) {
			if (ch != 'a' && ch != 'b') flag = false;
		}

		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] == 'b') b1 = i + 1;
		}

		for (int i = 0; i < s2.size(); ++i) {
			if (s2[i] == 'b') b2 = i + 1;
		}
		mp[b2 - b1].push_back({b1, s1.size() - b2});

		s[hsh(s1)][hsh(s2)]++;
	}
	frac[0] = 1;
	for (int i = 1; i <= 1e6; ++i) frac[i] = frac[i - 1] * i;


	if (flag) {
		for (int i = 1; i <= q; ++i) {
			string t1, t2;
			cin >> t1 >> t2;
			if (t1.size() != t2.size()) {
				cout << 0 << endl;
				continue;
			}
			int b1, b2;
			for (int i = 0; i < t1.size(); ++i) {
				if (t1[i] == 'b') b1 = i + 1;
			}

			for (int i = 0; i < t2.size(); ++i) {
				if (t2[i] == 'b') b2 = i + 1;
			}
			int ans = 0;
			for (const auto &t : mp[b2 - b1]) {
				int x = t.first, y = t.second;
				if (x <= b1 && y <= t2.size() - b2) ans++;

			}
			cout << ans << "\n";
		}
	} else {
		for (int i = 1; i <= q; ++i) {
			string t1, t2;
			cin >> t1 >> t2;
			if (t1.size() != t2.size()) {
				cout << 0 << endl;
				continue;
			}
			int m = t1.size();
			vector<ui128> ht1(m + 1), ht2(m + 1);
			int l = 1e7, r = 0;
			for (int i = 0; i < m; ++i) {
				if (t1[i] != t2[i]) {
					l = i + 1;
					break;
				}
			}
			for (int i = m - 1; i >= 0; --i) {
				if (t1[i] != t2[i]) {
					r = i + 1;
					break;
				}
			}
			for (int i = 1; i <= m; ++i) {
				ht1[i] = ht1[i - 1] * BASE + t1[i - 1] - 'a' + 1;
				//			cout << ht1[i] << " \n"[i == m];
				ht2[i] = ht2[i - 1] * BASE + t2[i - 1] - 'a' + 1;
			}
			int ans = 0;
			for (int i = l; i >= 1; --i) {
				for (int j = r; j <= m; ++j) {
					//				cout << i << " " << j << "\n";
					ans += s[hsh1(i, j, ht1)][hsh1(i, j, ht2)];
				}
			}
			cout << ans << "\n";
//			l = 2, r = 2;
//			cerr << hsh1(l, r, ht1) << ' ' << hsh(t1.substr(l - 1, r - l + 1)) << " " << t1.substr(l - 1, r - l + 1) << endl;
//			cerr << l << " " << r << endl;
//			cerr << (unsigned long long)hsh1(l, r, ht1) << " " << (unsigned long long)hsh1(l, r, ht2) << endl;
		}
	}
	return 0;
}
