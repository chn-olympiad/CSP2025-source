#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define per(i,x,y) for (int i = x; i >= y; i--)
using namespace std;
const int N = 1e4, mod = 998244353;
int c[N], n, m, cnt = 0;
long long ans = 1;
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	rep(i, 1, n) {
		scanf("%d", c + i);
		if (c[i] == 0) cnt++;
	}
	if (n - cnt < m) {
		cout << 0 << endl;
		return 0;
	}
	int flag = 1;
	rep(i, 0, int(s.size())-1) {
		if (s[i] != '1') flag = 0;
	}
	if (flag) {
		rep(i, 1, n) {
			ans = ans * i % mod;
		}
		cout << ans << endl;
		return 0;
	}

}
