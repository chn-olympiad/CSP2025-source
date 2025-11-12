#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1, MOD = 998244353;

int n, m, ans, s[MAXN], c[MAXN], b[MAXN];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if(m == n) {
		for(int i = 1; i <= n; i++) {
			if(!s[i] || !c[i]) {
				cout << 0;
				return 0;
			}
		}
		int res = 1;
		for(int i = 1; i <= n; i++) {
			res *= i;
			res %= MOD;
		}
		cout << res;
		return 0;
	}
	iota(b + 1, b + n + 1, 1);
	do {
		int sum = 0, res = 0;
		for(int i = 1; i <= n; i++) {
			int now = b[i];
			if(!s[i]) {
				sum++;
			}
			else {
				if(sum >= c[now]) {
					sum++;
				}
				else {
					res++;
				}
			}
		}
//		cout << res << "\n";
		ans += (res >= m);
	}while(next_permutation(b + 1, b + n + 1));
	cout << ans;
	return 0;
}
