#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q, a[N];
struct String {
	string x, y;
	bool operator < (const String cmp) const {
		return x.size() < cmp.x.size();
	}
} str[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> str[i].x >> str[i].y;
	sort(str + 1, str + n + 1);
	for (int i = 1; i <= n; ++i)
		a[i] = str[i].x.size();
	while (q--) {
		string s, t;
		cin >> s >> t;
		if (s.size() != t.size()) {
			puts("0");
			continue;
		}
		int ans = 0;
		size_t p1 = 0, p2 = 0, pre, suf;
		while (p1 < s.size() && p2 < t.size() && s[p1] == t[p2]) ++p1, ++p2;
		pre = p1;
		p1 = 0, p2 = 0;
		while (p1 < s.size() && p2 < t.size() && s[s.size() - p1 - 1] == t[t.size() - p2 - 1]) ++p1, ++p2;
		suf = p1;
		for (size_t i = 0; i <= pre; ++i) {
			int lef = lower_bound(a + 1, a + n + 1, s.size() - i - suf) - a;
			int rig = upper_bound(a + 1, a + n + 1, s.size() - i) - a - 1;
			for (int j = lef; j <= rig; ++j) {
				if (i + a[j] > s.size()) continue;
				if (i + a[j] < s.size() - suf) continue;
				string sy = s.substr(i, a[j]);
				if (sy != str[j].x) continue;
				string ty = t.substr(i, a[j]);
				if (ty != str[j].y) continue;
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}