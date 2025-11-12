#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 10;
int n, q, ans;
std::string s[N][2], t[2];

void dfs(int x, std::string p) {
	if (p == t[1]) {
		++ans;
		return;
	}
	if (x == n + 1) 
		return;
	int len = p.size(), ls = s[x][0].size();
	std::string np = "";
	for (int i = 0; i < len; i++) {
		bool ok = true;
		for (int j = 0; ok && j < ls; j++)
			if (p[i] != s[x][0][j]) 
				ok = false;
		if (ok) {
			np += s[x][1];
			for (int j = i + ls; j < len; j++)
				np.push_back(p[j]);
			dfs(x + 1, np);
		} else np.push_back(p[i]);
	}
	dfs(x + 1, np);
}

int main() {
	freopen("replace1.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i][0] >> s[i][1];
	}

	for (; q--; ) {
		std::cin >> t[0] >> t[1];
		ans = 0;
		dfs(1, t[0]);
		printf("%d\n", ans);
	}
}