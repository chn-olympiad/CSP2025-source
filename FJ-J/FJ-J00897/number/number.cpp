#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> g;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i ++) {
		if(s[i] <= '9' && s[i] >= '0') g.push_back(s[i] - '0');
	} sort(g.begin(), g.end()); reverse(g.begin(), g.end());
	for(int i = 0; i < g.size(); i ++) printf("%d", g[i]);
	return 0;
}
