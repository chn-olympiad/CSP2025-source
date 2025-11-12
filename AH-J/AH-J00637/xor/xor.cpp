#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], s[500010], cnt;
struct Range {
	int l, r;
}p[1000010];
bool cmp(const Range& a, const Range& b) {
	return a.r < b.r;
}
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if ((s[j] ^ s[i - 1]) == k)
				p[++cnt] = (Range){i, j};
	sort(p + 1, p + cnt + 1, cmp);
	int ans = 0, now = 0;
	for (int i = 1; i <= cnt; i++)
		if (now < p[i].l) {
			ans++;
			now = p[i].r;
		}
	cout << ans << '\n';
	return 0;
}
