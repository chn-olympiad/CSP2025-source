#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m, a[N], b[N], p[N];

/*

定义 dp[i][j][k] 为第 i 天选择第 j 个人且面试成功 k 人的方案数 

若 dp[1~n][j][c[i] + 1 ~ n] = 0 则 dp[i][j][k] += 0;

否则 dp[i][j][k]++; 

*/

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	int res = 0;
	do {
		int suc = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '0') {
				cnt++;
				continue;
			} else {
				if (cnt >= b[p[i]]) {
//					cout << 
					cnt++;
					continue;
				}
				suc++;
			}
		}
		if (suc >= m) {
//			cout << m << '\n';
			res++;
			res %= 998244353; 
		}
	
	} while (next_permutation(p + 1, p + 1 + n));
	cout << res;
	return 0;
}

