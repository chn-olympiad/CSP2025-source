#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int N = 5e3 + 5;
const long long mod = 998244353;
int n;
int a[N];
long long ans;
map<string, bool> mp; 
void dfs(int pos, int id, int maxn, int sum, string cho) {
	if (pos >= 3) {
		if (sum > maxn * 2) {
			if (!mp[cho])
				mp[cho] = 1, ans = (ans + 1) % mod;
		}
		if (pos == n)
			return;
	}
	for (int i = id + 1; i <= n; i++) {
		dfs(pos + 1, i, max(maxn, a[i]), sum + a[i], cho + char(i + '0'));
		dfs(pos, i, maxn, sum, cho);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	dfs(0, 0, 0, 0, "");
	printf("%lld", ans);
	return 0;
}
