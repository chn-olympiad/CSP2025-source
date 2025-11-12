#include <bits/stdc++.h>
using namespace std;

// for every t1, t2
// find t1[i..j] = s1 and t2[i..j] = s2 and i <= l j >= r
// if I construct the fail tree and s1, s2
// for s[k], I'm asking whether u and v have beem in st1[k] and st2[k] simultaneously
// single k can only affect once?
// yes

// 

// for B
// condition: move b k blocks
// 

int n, q;
string s1[200010], s2[200010];
vector<int> sf1[200010], sf2[200010];
int sz[200010];

void gen_fail(string s, vector<int>& f) {
	s = ' ' + s;
	f.assign(s.size(), 0);
	for (int i = 2; i < s.size(); i++) {
		int j = f[i - 1];
		while (j > 0 && s[j + 1] != s[i]) j = f[j];
		if (s[j + 1] == s[i]) j++;
		f[i] = j;
	}
}

int cnti(const string& t1, const string& t2, int k, int l, int r) {
	int cnt = 0;
//	cout << k << endl;
	for (int i = 0, j1 = 0, j2 = 0; i < t1.size(); i++) {
		while (j1 > 0 && s1[k][j1] != t1[i]) j1 = sf1[k][j1];
		while (j2 > 0 && s2[k][j2] != t2[i]) j2 = sf2[k][j2];
		if (s1[k][j1] == t1[i]) j1++;
		if (s2[k][j2] == t2[i]) j2++;
//		cout << j1 << " " << t1[i] << " " << t1[j1 - 1] << endl;
		if (j1 == sz[k] && j2 == sz[k] && i >= r && (i - sz[k] + 1) <= l) {
			cnt++;
//			cout << k << " " << i + 1 << endl;
		}
	}
	return cnt;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		gen_fail(s1[i], sf1[i]);
		gen_fail(s2[i], sf2[i]);
		sz[i] = sf1[i].size() - 1;
	}
	
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int l = 0, r = t1.size();
		while (t1[l] == t2[l]) l++;
		while (t1[r] == t2[r]) r--;
		long long sum = 0;
		for (int i = 1; i <= n; i++) sum += cnti(t1, t2, i, l, r);
		cout << sum << "\n";
	}
}
