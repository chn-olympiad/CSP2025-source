#include <bits/stdc++.h>
using namespace std;
map<string, string> mp;
map<string, int> dis;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	for (int i = 1; i <= m; i ++) {
		string s1, s2;
		queue<pair<string, int> > q;
		q.push({s1, 0});
		dis[s1] = 0;
		bool fg = 0;
		while (q.size()) {
			string now = q.front().first;
			int idx = q.front().second;
			q.pop();
			if (now == s2) {
				cout << dis[now] << endl;
				fg = 1;
				break;
			}
			for (int i = idx; i < now.size(); i ++) {
				for (int j = 0; i + j < now.size(); j ++) {
					if (mp.count(now.substr(i, j))) {
						string nxt = now.substr(0, i) + mp[now.substr(i, j)] + now.substr(i + j, now.size());
						dis[nxt] = dis[now] + 1;
						q.push({nxt, i + j});
					}
				}
			}
		}
		if (!fg) cout << 0 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

