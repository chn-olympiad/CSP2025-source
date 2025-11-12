// lichenxi108.rp = inf;
#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
int n, q, nn1 = 1, nn2 = 1, trie1[N][26], trie2[N][26], cnt;
map<int, bool> mp1[N], mp2[N]; 

void ins1(string s) {
	int tmp = 1;
	for (int i = 0; i < s.size(); i++) {
		if (!trie1[tmp][s[i] - 'a']) trie1[tmp][s[i] - 'a'] = ++nn1;
		tmp = trie1[tmp][s[i] - 'a'];
	}
	++cnt;
	mp1[tmp][(cnt + 1) / 2] = 1;
}

void ins2(string s) {
	int tmp = 1;
	for (int i = 0; i < s.size(); i++) {
		if (!trie2[tmp][s[i] - 'a']) trie2[tmp][s[i] - 'a'] = ++nn2;
		tmp = trie2[tmp][s[i] - 'a'];
	}
	++cnt;
	mp2[tmp][(cnt + 1) / 2] = 1;
}

void solve() {
	string s, t;
	cin >> s >> t;
	if (s.size() != t.size()) {
		cout << "0\n";
		return;
	}
	int len = s.size();
	int l = 0, r = len - 1, ans = 0;
	while (l < len && s[l]== t[l]) ++l;
	while (r && s[r] == t[r]) --r;
	for (int i = 0; i <= l && i < len; i++) {
		int tmp1 = 1, tmp2 = 1;
		for (int j = i; j < len; j++) {
			if (!trie1[tmp1][s[j] - 'a'] || !trie2[tmp2][t[j] - 'a']) break;
			tmp1 = trie1[tmp1][s[j] - 'a'];
			tmp2 = trie2[tmp2][t[j] - 'a'];
			if (j < r) continue; 
			map<int, int> tmp;
			for (auto k : mp1[tmp1]) {
				tmp[k.first]++;
			}
			for (auto k : mp2[tmp2]) {
				tmp[k.first]++;
			}
			for (auto k : tmp) {
				if (k.second == 2) ++ans;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	while (n--) {
		string a, b;
		cin >> a >> b;
		ins1(a), ins2(b);
	}
	while (q--) {
		solve();
	}
	return 0;
} 
