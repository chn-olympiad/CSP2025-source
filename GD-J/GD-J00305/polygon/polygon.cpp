#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
ll a[5020];
ll ans = 0;
bool vis[5020];
inline void dfs(int i, int j, ll sum, ll ma) {//n选k l代表选了多少个 
	if (j == 0) {
		if (sum > ma * 2)
			++ans;
		return;
	}
	else
		for (int p = 1; p <= i; ++p) {
			if (vis[p] == false) {
				vis[p] = true;
				dfs(i, j - 1, sum + a[p], max(ma, a[p]));
				vis[p] = false;
			}
		}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	memset(vis, false, sizeof(vis));
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (register int i = 3; i <= n; ++i) {
		for (register int j = 3; j <= i; ++j) {
			dfs(i, j, 0ll, 0ll);//前i个里面选j个数字，看是否组成 ,以a[i]为最大值 
			memset(vis, false, sizeof(vis));
			ans %= 998244353;
		}
	}
	cout << ans / 32;
}
