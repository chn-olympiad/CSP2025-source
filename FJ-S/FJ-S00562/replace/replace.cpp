#include <bits/stdc++.h>
#define ri register int

using namespace std;
typedef long long ll;

constexpr int N = 2e5 + 3;

int n, m;

string s[N][2];
string t[N][2];

inline void slv1() {
	map<string, int> mp;
	for(ri i = 1; i <= n; ++i) mp[s[i][0]] = i;
	string str[2];
	string sstr[2];
	for(ri i = 1; i <= m; ++i) {
		int len = t[i][0].size();
		int l = 0, r = len - 1, ans = 0;
		while(l < len && t[i][0][l] == t[i][1][l]) ++l;
		while(r >= 0 && t[i][0][r] == t[i][1][r]) --r;
		sstr[0] = sstr[1] = "";
		for(ri j = l; j <= r; ++j) {
			sstr[0] = sstr[0] + t[i][0][j];
			sstr[1] = sstr[1] + t[i][1][j];
		}
		str[0] = sstr[0], str[1] = sstr[1];
		if(s[mp[str[0]]][1] == str[1]) ++ans;
		for(ri k = r + 1; k < len; ++k) {
			str[0] = str[0] + t[i][0][k];
			str[1] = str[1] + t[i][1][k];
			if(mp.count(str[0]) && s[mp[str[0]]][1] == str[1]) ++ans;
		}
		for(ri j = l - 1; j >= 0; --j) {
			sstr[0] = t[i][0][j] + sstr[0];
			sstr[1] = t[i][1][j] + sstr[1];
			str[0] = sstr[0], str[1] = sstr[1];
			if(s[mp[str[0]]][1] == str[1]) ++ans;
			for(ri k = r + 1; k < len; ++k) {
				str[0] = str[0] + t[i][0][k];
				str[1] = str[1] + t[i][1][k];
				if(mp.count(str[0]) && s[mp[str[0]]][1] == str[1]) ++ans;
			}
		}
		cout << ans << "\n";
	}
}

inline void Solve() {
	cin >> n >> m;
	for(ri i = 1; i <= n; ++i) cin >> s[i][0] >> s[i][1];
	int L2 = 0;
	for(ri i = 1; i <= m; ++i) cin >> t[i][0] >> t[i][1], L2 += t[i][0].size(), L2 += t[i][1].size();
slv1();
	
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
	return 0;
}

