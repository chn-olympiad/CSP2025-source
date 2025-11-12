#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int n, m, a[505];
bool s[505], vis[505];
int p[505];
ll ans = 0;
void dfs(int t) {
	if (t == n + 1) {
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= a[p[i]] || !s[i])
				cnt++;
			else
				res++;	
		}
		ans += res >= m;
		return ;
	} 
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			p[t] = i;
			dfs(t + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1);
	cout << ans << '\n';
	return 0;
} 
