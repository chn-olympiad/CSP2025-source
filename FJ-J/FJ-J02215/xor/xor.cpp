#include <bits/stdc++.h>
using namespace std;
int ans, n, mx, k;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; ++ i)
		cin >> a[i], pre[i] = (pre[i - 1] ^ a[i]), mx = max(mx, pre[i]);
	vector<int> lst(mx + 1, 0x3f3f3f3f);
	lst[0] = 0;
	vector<pair<int, int>> area;
	for(int r = 1; r <= n; ++ r) {
		int l = lst[pre[r] ^ k] + 1;
		lst[pre[r]] = r;
		if(l > r) continue;
		area.push_back({ l, r });
	}
	int r = 0, tot = 0;
	sort(area.begin(), area.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
		return a.second < b.second;
	});
	while(tot < area.size()) {
		while(tot < area.size() && area[tot].first <= r) ++ tot;
		if(tot >= area.size()) break;
		++ ans;
		r = area[tot].second;
	}
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
