#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const int kMaxN = 2e5 + 5, kMaxL = 5e6 + 5;

struct node {
	string s1, s2;
	int l, r, len;
};

int n, q, tot, cnt[kMaxL * 2];
string s1, s2;
unordered_map<string, int> mp;
vector<node> v[kMaxN];

void getdif(string s1, string s2, int &l, int &r) {
	l = -1, r = 0;
	for (int j = 0; j < s1.size(); j++) {
		if (s1[j] != s2[j]) {
			if (l < 0)
				l = j;
			r = j;
		}
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		int l = 0, r = 0;
		getdif(s1, s2, l, r);
		if (l == -1)
			continue;
		string dif = s1.substr(l, r - l + 1);
		if (!mp.count(dif))
			mp[dif] = ++tot;
		v[mp[dif]].push_back((node){s1, s2, l, r, (int)s1.size()});
	}
	for (; q; q--) {
		cin >> s1 >> s2;
		int l = 0, r = 0, ans = 0;
		getdif(s1, s2, l, r);
		string dif = s1.substr(l, r - l + 1);
		if (!mp.count(dif)) {
			cout << "0\n";
			continue;
		}
		for (node i : v[mp[dif]]) {
			if (l < i.l || i.len - i.r - 1 > s1.size() - r - 1)
				continue;
			ans += (i.s1 == s1.substr(l - i.l, r + i.len - i.r - 1 - l + i.l + 1) && i.s2 == s2.substr(l - i.l, r + i.len - i.r - 1 - l + i.l + 1));
		}
		cout << ans << '\n';
	}
	return 0;
}
//我错了我下次一定复习字符串 
