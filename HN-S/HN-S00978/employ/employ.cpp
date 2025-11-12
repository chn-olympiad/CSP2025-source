#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int a[N];
bool vis[N];
int ans[N];
int n, m;
string s;
int cnt = 0;

bool check() {
	int q = 0, z = 0;
	for (int l = 1; l <= n; ++l) {
		int i = ans[l];
		if (s[l - 1] == '0' || q >= a[i]) {
			q++;
		}
		else z++;
	}
	return z >= m;
}

void dfs(int cur) {
	if (cur == n + 1) {
//		for (int i = 1; i <= n; ++i) {
//			cout << ans[i] << ' ';
//		}
//		cout << "\n";
		if (check()) {
			cnt = (cnt + 1) % mod; 
		}
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			vis[i] = 1;
			ans[cur] = i;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dfs(1);
	cout << cnt;
	return 0;
}
// Ren5Jie4Di4Ling5%
