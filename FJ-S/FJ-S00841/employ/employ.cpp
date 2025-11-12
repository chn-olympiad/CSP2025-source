#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N]; char s[N];
int ans, a[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int check() {
	int cnt = 0, k = 0;
	for (int i = 1; i <= n; i++) {
		if(c[a[i]] <= k) k ++;
		else if(s[i] == '1') cnt ++;
		else k ++;
	} return cnt >= m;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; i++) cin >> c[i];
	if(n <= 10) {
		do {
			ans = (ans + check()) % mod;
		}while(next_permutation(a + 1, a + n + 1));
		cout << ans;
	}
	else cout << 0;
	return 0;
}
