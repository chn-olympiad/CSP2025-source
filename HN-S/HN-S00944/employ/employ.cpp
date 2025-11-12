#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n, m, a[100005], g, lie[100005];
bool flag[100005];
string s;
void dfs (int x) {
	if (x > n) {
		int pass = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (pass >= a[lie[i]]) {
				pass++; continue;
			}
			if (s[i - 1] == '0') {
				pass++;
			} else {
				pass = 0; ans++;
				ans %= MOD;
			}
		}
		if (ans >= m) {
			g++;
//			for (int i = 1; i <= n; i++) {
//				cout << lie[i] << " ";
//			} cout << "\n";
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			lie[x] = i;
			flag[i] = 1;
			dfs(x + 1);
			flag[i] = 0; 
		}
	}
} 
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
//	int gg = 1;
//	for (int i = 1; i < 500; i++) {
//		gg *= i;
//		gg %= MOD;
//	} gg *= 333; gg %= MOD;
//	cout << gg << "\n"; 
	int cnt = 0, wei;
	for (int i = s.size() - 1; i >= 0; i--) {
		cnt += (s[i] == '1');
		if (s[i] == '1') wei = i + 1;
	}
	bool kk = 1; int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) kk = 0;
//		if (a[i] == 0) sum++;
	}
//	cout << sum << "\n";
	if (m == n) {
		if (!kk) {
			cout << 0; return 0;
		}
		if (cnt == n) {
			int ans = 1;
			for (int i = 1; i <= n; i++) {
				ans *= i;
				ans %= MOD; 
			} cout << ans; return 0;
		} else {
			cout << 0; return 0;
		}
	}
//	if (m == 1) {
//		sort(a + 1, a + n + 1);
//		int ceng = 0;
//		for (int i = n; i >= 1; i--) {
//			if (a[i] >= wei) ceng++;
//			else break;
//		}
////		cout << ceng << "\n";
//		int ans = 1;
//			for (int i = 1; i < n; i++) {
//				ans *= i;
//				ans %= MOD; 
//			} ans *= ceng;
//			ans %= MOD;
//			cout << ans; return 0; 
//	}
	dfs(1);
	cout << g;
	return 0;
}
// We will win in CSP-S2025!
// We will have 210 pts!
// 16:50 100 + 20 + 10 now 
// 17:55 166!
