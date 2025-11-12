#include <bits/stdc++.h>
using namespace std;
struct node {
	string s, t;
} a[50001];
int find_cnt(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'b') {
			return i;
		}
	}
}
int find_sum(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'b') {
			return s.size() - i - 1;
		}
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q, ans = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].t;
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		string s;
		string t;
		cin >> s >> t;
		int cnts = find_cnt(s);
		int cntss = find_sum(s);
		int cntt = find_cnt(t);
		for (int j = 1; j <= n; j++) {
			int sums = find_cnt(a[j].s);
			int sumss = find_sum(a[j].s);
//			cout << a[j].s << endl;
//			cout << sums << " " << cnts << " " << sumss << " " << cntss << endl;
			if (sums > cnts || sumss > cntss) {
				continue;
			}
			string c = "";
			for (int k = 1; k <= cnts - sums; k++) {
				c += 'a';
//				cout << c << endl;
			}
			c += a[j].t;
			for (int k = 1; k <= cntss - sumss; k++) {
				c += 'a';
			}
//			cout << c << endl << t << endl;
			if (c == t) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
