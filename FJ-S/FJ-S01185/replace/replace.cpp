#include <bits/stdc++.h>

using namespace std;

int n, q;
string s[200005][3], x, y, s_;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][1] >> s[i][2];
	}
	while (q--) {
		int ans = 0;
		cin >> x >> y;
		int len = x.size();
		for (int i = 1; i <= n; ++i) {
			int pos = 0;
			while (1) {
				auto p = x.find(s[i][1], pos);
				if (p == string::npos) break;
				//cout << x.substr(0, p) << '\n';
				//cout << s[i][2] << '\n';
				//cout << x.substr(p + s[i][1].size(), len - p - s[i][1].size()) << '\n';
				pos = p + s[i][1].size();
				
				if (x.substr(0, p) + 
					s[i][2] + 
					x.substr(p + s[i][1].size(), len - p - s[i][1].size())
					 == y) ans++;
				
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
/*
我不会任何的字符串算法。 
*/
