#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500;
const int M = 998244353;
int n, m, c[N+5], p[N+5];
string s;
void solve1 () {
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		p[i] = i;
	}
	do {
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i ++) {
			if (s[i] == '0' || cnt >= c[p[i]]){
				cnt ++;
			}
			else {
				res ++;
			}
		}
		ans = (ans + (res >= m)) % M;
	} while (next_permutation(p+1, p+1+n));
	cout << ans;
}
void solve2() {
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
	}
	if (n <= 10) {
		solve1();
	}
	else {
		cout << 0;
	}
	return 0;
}

