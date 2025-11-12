#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn][5];
int count(string s, char c) {
	int ans = 0;
	for (char d : s) {
		if (d == c) {
			++ans;
		}
	}
	return ans;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				cin >> a[i][j];
			}
		}
		queue<string> que;
		que.push("");
		int maxa = -1e9;
		while(que.size()) {
			string t = que.front();
			que.pop();
			if (t.size() == n) {
				int ans = 0;
				for (int i = 0; i < n; ++i) {
					ans += a[i + 1][t[i]];
				}
				maxa = max(ans, maxa);
				continue;
			}
			for (char c = 1; c <= 3; ++c) {
				if (count(t, c) < n / 2) {
					que.push(t + c);
				}
			}
		}
		cout << maxa << "\n";
	}
}
