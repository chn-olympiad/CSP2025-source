#include <bits/stdc++.h>
using namespace std;
int q, n, ans;
map<string, vector<int> > mp1;
map<int, string > mp2;
string str, str1;
void qc(string &a, string &b) {
	int sa = a.size(), l, r;
	string na = "", nb = "";
	for (int i = 0; i < sa; i++) {
		l = i;
		if (a[i] != b[i]) {
			break;
		}
	}
	for (int i = sa - 1; i >= 0; i--) {
		r = i;
		if (a[i] != b[i]) {
			break;
		}
	}
	for (int i = l; i <= r; i++) {
		nb = nb + b[i];
		na = na + a[i];
	}
	a = na;
	b = nb;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> str >> str1;
		qc(str, str1);
		mp1[str].push_back(i);
		mp2[i] = str1;
	}
	for (int i = 1; i <= q; i++) {
		cin >> str >> str1;
		qc(str, str1);
		int sz = mp1[str].size();
		for (int i = 0; i < sz; i++) {
			if (mp2[mp1[str][i]] == str1) ans++;
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}