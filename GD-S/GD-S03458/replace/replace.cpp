#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 5e6 + 5;
const int base = 233333;
int n, q;
ull h1[N], h2[N], pw[N];
map<ull, set<ull>> mp;
inline ull get_hash(string str) {
	ull res = 0;
	for (int i = 1; i < str.size(); i++) res = res * base + str[i];
	return res;
}
inline ull get_hash1(int l, int r) {
	return h1[r] - h1[l - 1] * pw[r - l + 1];
}
inline ull get_hash2(int l, int r) {
	return h2[r] - h2[l - 1] * pw[r - l + 1];
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * base;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		s1 = ' ' + s1, s2 = ' ' + s2;
		mp[get_hash(s1)].insert(get_hash(s2));
	}
	while (q--) {
		string s1, s2;
		cin >> s1 >> s2;
		s1 = ' ' + s1, s2 = ' ' + s2;
		if (s1.size() != s2.size()) {
			cout << 0 << '\n';
			continue ;
		}
		int l, r, ans = 0;
		for (int i = 1; i < s1.size(); i++)h1[i] = h1[i - 1] * base + s1[i];
		for (int i = 1; i < s2.size(); i++)h2[i] = h2[i - 1] * base + s2[i];
  		for (int i = 1; i < s1.size(); i++) {if (s1[i] != s2[i]) {l = i; break;}}
		for (int i = s1.size() - 1; i >= 1; i--) {if (s1[i] != s2[i]) {r = i; break;}}
		for (int i = 1; i <= l; i++) for (int j = r; j < s1.size(); j++) if (mp[get_hash1(i, j)].count(get_hash2(i, j)))ans++;
		cout << ans << '\n';
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
