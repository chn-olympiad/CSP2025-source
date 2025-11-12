#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n, ans, a[5005];
bool vis[5005];
void DFS(int pos, int maxsticks, int othersticks) {
	if (othersticks + maxsticks > 2 * maxsticks && pos == n + 1) ans = ans % MOD + 1;
	if (pos > n || vis[pos]) return;
	vis[pos] = 1;
	if (maxsticks < a[pos]) DFS(pos + 1, a[pos], othersticks + maxsticks);
	else DFS(pos + 1, maxsticks, othersticks + a[pos]);
	vis[pos] = 0;
	DFS(pos + 1, maxsticks, othersticks);
	return;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	DFS(1, 0, 0);
	cout << ans % MOD << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}