#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL MAXN = 5e2+5, MOD = 998244353;
LL n, m, c[MAXN];
bool vis[MAXN];
char s[MAXN];

LL dfs(LL x, LL f) { // 现在是第x天，前几天有f个人失败 
	if (x > n) {
//		cout << "f:" << f << endl;
		if (f <= n-m) return 1;
		return 0;
	}
	LL res = 0;
//	cout << "day " << x << " f:" << f << endl;
	for (LL i = 1; i<=n; i++) {
		if (!vis[i]) { // i不在日程 
//			cout << "day " << x << ": " << i << " c:" <<  c[i]  << " f:" << f << endl;
			vis[i] = true;
			if (c[i] <= f || s[x] == '0')
				res = (res+dfs(x+1, f+1))%MOD;
			else
				res = (res+dfs(x+1, f))%MOD;
			vis[i] = false;
		}
	}
	return res;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s+1;
	for (LL i = 1; i<=n; i++) cin >> c[i];
	cout << dfs(1, 0);
	return 0;
}
