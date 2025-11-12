#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5; 
int t, n, ans = INT_MIN;
int pos[105];
struct node {
	int a, b, c;
}e[N];
void dfs(int val, int k) {
	if (k == n + 1) {
		ans = max(ans, val);
		return ;
	}
	for (int i = 1; i <= 3; i ++) {
		if (i == 1 && pos[i] + 1 <= n / 2) {
			pos[i] ++;
			dfs(val + e[k].a, k + 1);
			pos[i] --;
		}
		else if (i == 2 && pos[i] + 1 <= n / 2) {
			pos[i] ++;
			dfs(val + e[k].b, k + 1);
			pos[i] --;
		}
		else if (i == 3 && pos[i] + 1 <= n / 2) {
			pos[i] ++;
			dfs(val + e[k].c, k + 1);
			pos[i] --;
		}
	}
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t --) {
		memset(pos, 0, sizeof(pos));
		ans = INT_MIN;
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> e[i].a >> e[i].b >> e[i].c;
		}
		dfs(0, 1);
		cout << ans << '\n';
	} 
	return 0;
}
