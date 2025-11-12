#include <bits/stdc++.h>
int n, q;
std::string s[200005][2];
void solve1() {
	for (std::string a, b; q--;) {
		std::cin >> a >> b;
		if (a.size() != b.size()) {std::cout << "0\n"; continue;}
		int ans = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < a.size();) {
			std::string tmp = a;
			int pos = tmp.find(s[i][0], j);
			if (pos == std::string::npos) break;
			tmp = tmp.substr(0, pos) + s[i][1];
			if (pos + s[i][0].size() < a.size())
				tmp += a.substr(pos + s[i][0].size());
			if (tmp == b) ++ans;
			j = pos + 1;
		}
		std::cout << ans << '\n';
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin >> n >> q;
	for (int i = 0; i < n; ++i) std::cin >> s[i][0] >> s[i][1];
	solve1();
}
