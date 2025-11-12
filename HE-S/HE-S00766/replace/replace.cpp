#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2, string t1, string t2) {
	for (int i = 0; i < t1.size(); i ++) {
		bool flag = 1;
		int cnt = 0;
		for (int j = i; j < t1.size() && cnt < s1.size(); j ++) {
			if (t1[j] != s1[cnt]) {
				flag = 0;
				break ;
			}
			cnt ++;
		}
		if (!flag || cnt < s1.size()) continue ;
		string tmp;
		int pos = 0;
		while (pos < t1.size()) {
			if (pos == i) {
				tmp = tmp + s2;
				pos = i + s1.size();
				continue ;
			}
			tmp += t1[pos];
			pos ++;
		}
//		cout << "c i = " << i << "\n";
//		cout << "tmp = " << tmp << " t2 = " << t2 << "\n";
		if (tmp == t2) return 1;
	}
	return 0;
}

int n, q;
string s[1001][2];

void work() {
	string w1, w2;
	cin >> w1 >> w2;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
//		cout << "i = " << i << "\n";
		if (check(s[i][1], s[i][2], w1, w2)) {
			ans ++;
		}
	}
	cout << ans << "\n";
}

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) 
		cin >> s[i][1] >> s[i][2];
	while (q --) work();
	
	return 0;
}
