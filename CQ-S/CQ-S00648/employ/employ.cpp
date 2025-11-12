#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, c[510], ans;
bool vis[20];
int b[20];
string a;
inline void dfs(int step) {
	if (step == n + 1) {
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= b[i] || a[i] == '0') {
				cnt++;
			} else {
				res++;
			}
		}
		if (res >= m) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			b[step] = c[i];
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> a;
	a = " " + a; 
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n <= 18) {
		dfs(1);
		cout << ans;
		return 0;
	}
	
	return 0;
}

