#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 505;
const int mod = 998244353;
bool vis[maxn];
string s;
int a[maxn];
int dis[maxn];
int n, m;
long long ans;

void dfs(int i, int cnt) {
	if (i>n) {
		if (n-cnt >= m) ans++;
		ans %= mod;
		return;
	}
	bool f = 1;
	for (int j=1; j<=n; j++) {
		if (!vis[j]) {
			if (cnt >= a[j] || s[i-1] == '0') f = 0;
			dis[i] = j;
			vis[j] = 1;
			if (f == 0) dfs(i+1, cnt+1);
			else dfs(i+1, cnt);
			vis[j] = 0;
			f = 1;
		}
	}
}

signed main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	int cnt = 0;
	for (int i=0; i<s.size(); i++) if (s[i] == '1') cnt++;
	if (cnt < m) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i=1; i<=n; i++) cin >> a[i];
	dfs(1, 0);
	cout << ans << '\n';
}
