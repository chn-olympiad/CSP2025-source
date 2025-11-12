#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N], pre[N], cnt;
struct Line {
	int l, r;
}t[N];
map<int, int> mp;
bool cmp(Line A, Line B) {
	return A.r < B.r;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> k, mp.clear();
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] ^ a[i];
	for (int i = n; i >= 0; i--) {
		if (mp.count(pre[i] ^ k)) t[++cnt] = {i + 1, mp[pre[i] ^ k]};
		mp[pre[i]] = i;
	}
	sort(t + 1, t + cnt + 1, cmp);
	int ans = 0, lst = 0;
	for (int i = 1; i <= cnt; i++)
		if (lst < t[i].l) ans++, lst = t[i].r;
	cout << ans << "\n";
	return 0;
}

