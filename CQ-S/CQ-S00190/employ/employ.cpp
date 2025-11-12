#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans;
string s;
int a[1005], b[1005];
int nb[1005];
void f(int k, int taotairenshu) {
	if (k == n + 1) {
		if (n - taotairenshu >= m) {
			ans ++;
//			for (int i = 1; i < k; i ++) {
//				cout << nb[i];
//			}
//			cout << '\n';
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (b[i] == 0) {
			int cnt = 0;
			nb[k] = i;
			if (a[i] <= taotairenshu) {
				cnt = 1;
			}
			if (s[k] == '0') {
				cnt = 1;
			}
			b[i] = 1;
			f(k + 1, taotairenshu + cnt);
			b[i] = 0;
		}
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	f(1, 0);
	cout << ans;
	return 0;
	 
}
//2204128

