#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
using lnt = long long;
using std::cin;
using std::cout;

void stream_init() {
	cin.tie(nullptr)->sync_with_stdio(false);
}

// «Î ‰»Î

const int max_n = 2e6 + 20;

std::string s[max_n][2];

std::string replace(std::string a, int pos, std::string b) {
	for (int i = 0; i < b.size(); ++i) {
		a[i + pos] = b[i];
	}
	return a;
}

void solve() {
	int n, m; cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		cin >> s[i][0] >> s[i][1];
	}
	
	while (m--) {
		std::string a, b; cin >> a >> b;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int bg = 0;
			while (bg < a.size()) {
				bg = a.find(s[i][0], bg);
				if (bg == -1) break;
				if (replace(a, bg, s[i][1]) == b) {
					++cnt;
				}
				++bg;
			}
		}
		printf("%d\n", cnt);
	}
	
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	stream_init();

	solve();
	
	return 0;
}
