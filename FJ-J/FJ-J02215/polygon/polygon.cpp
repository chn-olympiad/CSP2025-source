#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
#define int long long
int n, ans;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	auto dfs = [&](int x, int sum, int mx, int cnt, auto&& dfs) -> void {
		if(x > n) {
			if(cnt >= 3 && sum > (mx << 1))
				++ ans;
			return;
		}
		dfs(x + 1, sum, mx, cnt, dfs);
		dfs(x + 1, sum + a[x], max(mx, a[x]), cnt + 1, dfs);
	};
	dfs(1, 0, 0, 0, dfs);
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//mei zhao le DP da de wo tou teng xing tu
//shen sou 3min jiu da dui le 
