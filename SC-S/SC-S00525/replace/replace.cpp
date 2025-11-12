#include<bits/stdc++.h>
using namespace std;
const int N = 5.2e6+10, M = 2e5+10;
string s[M][2];
vector<int>slen[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		slen[s[i][0].size()].push_back(i);
	}
	string t1, t2;
	while (q--) {
		cin >> t1 >> t2;
		if (t1.size() != t2.size() || slen[t1.size()].empty())
			printf("0\n");
		else {
			auto & pos = slen[t1.size()];
			int ans = 0;
			for (int i = 0; i < pos.size(); i++)
				if (t1 == s[pos[i]][0] && t2 == s[pos[i]][1])
					ans += 2;
			printf("%d\n", ans);
		}
	}
}