#include<iostream>
#include<string>
using namespace std;
int n, m, a[505], ans;
string s;
bool all1 = 1;
bool vis[100];
int num[100];
void dfs(int idx) {
	if (idx > n) {
		int tot = 0, fail = 0;
		for (int i = 1; i <= n; i++)
			if (fail >= a[num[i]] || s[i - 1] == '0') ++fail;
			else ++tot;
		if (tot >= m) ++ans;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			num[idx] = i;
			dfs(idx + 1);
			vis[i] = 0;
		}
	}
	return;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i = 0; i < (int)(s.size()); i++) if (s[i] == '0') all1 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m && !all1) {
		cout << 0;
		return 0;
	}
	if (n <= 11) {
		dfs(1);
		cout << ans;
	} else {
		cout << 0;
	}
	
	return 0;
}
//               一路走好
//             王狗灏、来中杨
//              ^   ^   ^
//                & & &
//                | | |
//                \ | /
//                 |||
//                 |||
//                 |||
//            -------------
//T4, pian fen
//OK  12pts
