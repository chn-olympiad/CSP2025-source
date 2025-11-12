#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 5e6 + 2;
int n, q, len[N], d[N], nxt[N]; // cnt[M << 1];
string s1[N], s2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s1[i] >> s2[i], len[i] = s1[i].size();
	string t1, t2;
	while (q--) {
		cin >> t1 >> t2;
		int sz = t1.size();
		string s, tmp;
		int ans = 0;
		for (int idx = 1; idx <= n; ++idx) {
			s = s1[idx] + ' ' + t1;
			int j = 0;
			for (int i = 1; i < s.size(); ++i) {
				while (j && s[j] != s[i]) j = nxt[j - 1];
				j += s[j] == s[i];
				nxt[i] = j;
			}
			//cout << s << '\n';
			//for (int i = 1; i < s.size(); ++i)
				//cout << nxt[i] << ' ';
			//cout << '\n';
			for (int i = len[idx]; i < s.size(); ++i)
				if (nxt[i] == len[idx]) {
					tmp = t1; 
					//cout << i <<' ' << len[idx];
					for (int j = i - len[idx] - 1, p2 = len[idx] - 1; ~p2; --j)
						tmp[j] = s2[idx][p2--];
					//cout << 'k' << s2[idx] << ' ' << tmp << ' ' << t2 << '\n';
					ans += tmp == t2;
				}
		}
		cout << ans << '\n';
	}
	//for (int i = 1; i <= n; ++i) {
	//	cin >> s1[i] >> s2[i];
	//	len[i] = s1[i].size();
	//	int p1 = 0, p2 = 0;
	//	for (int j = 0; j < len[i]; ++j) {
	//		if (s1[i][j] == 'b') p1 = j;
	//		if (s2[i][j] == 'b') p2 = j;
	//	}
	//	++cnt[M + p2 - p1];
	//}
	//string t1, t2;
	//while (q--) {
	//	cin >> t1 >> t2;
	//	int sz = t1.size();
	//	if (sz != t2.size()) {
	//		cout << 0 << '\n';
	//		continue;
	//	}
	//	int p1 = 0, p2 = 0;
	//	for (int i = 0; i < sz; ++i) {
	//		if (t1[i] == 'b') p1 = i;
	//		if (t2[i] == 'b') p2 = i;
	//	}
	//	cout << cnt[M + p2 - p1] << '\n';
	//}
	return 0;
}
/*
g++ replace.cpp -o replace -std=c++14 -O2 -static
input5:
5 3
abd abc
at bt
cta cut
down dwno
all att
dabde dabce
dabde aabce
ctasabd cutsabc
output5:
1
0
0
*/