#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int n, m;
int a[maxn], pre[maxn];
vector<int> order;
bitset<maxn> ordered;
int dfs(int now) {
	if (order.size() == n) {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[order[i - 1]] > pre[i - 1] && pre[i] == pre[i - 1]) ans ++;
		}
		return ans >= m;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (ordered[i]) continue;
		ordered[i] = 1;
		order.push_back(i);
		ans += dfs(i);
		ordered[i] = 0;
		order.pop_back();
	}
	return ans;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	bool fg = 0;
	int idx;
	for (int i = 1; i <= n; i ++) {
		char c;
		cin >> c;
		bool can = c - '0';
		pre[i] = pre[i - 1] + !can;
		if (can && !fg) fg = 1, idx = i;
	}
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	cout << dfs(0) << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

