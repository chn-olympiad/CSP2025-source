#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10, MOD = 998244353;
int furry;
bool cmp(int x, int y) {
	return x > y;
}
int a[maxn];
bitset<maxn> vis;
bool chk() {
	int mx = 0, sum = 0, cnt = 0;
	for (int i = 1; i <= furry; i ++) {
		if (vis[i]) {
			cnt ++;
			mx = max(mx, a[i]);
			sum += a[i];
		}
	}
	return sum > (mx << 1) && cnt >= 3;
}
int dfs(int now, int sum, int mx) {
	vis[now] = 1;
	int ans = 0;
	if (chk()) ans ++;
	if (now == furry + 1) return ans;
	for (int i = now + 1; i <= furry; i ++) {
		if (!vis[i]) ans += dfs(i, sum + a[i], max(mx, a[i])), ans %= MOD;
	}
	vis[now] = 0;
	return ans;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> furry;
	for (int i = 1; i <= furry; i ++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= furry; i ++)
		ans += dfs(i, a[i], a[i]), ans %= MOD;
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// RP += 114514191981054181452 * getFkedTimes(CCF)

