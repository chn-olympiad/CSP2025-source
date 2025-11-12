#include <bits/stdc++.h>
#define il inline
using namespace std;

#define int long long
const int Maxn = 505;
const int Mod = 998244353;
int n, m, a[Maxn], c[Maxn], p[Maxn], ans, cnt[Maxn];
string str;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> str;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	for (int i = 1; i <= n; i ++) p[i] = i, a[i] = str[i - 1] - 48;
	bool tagA = 1;
	for (int i = 1; i <= n; i ++)
		if (a[i] == 0) {
			tagA = 0;
			break;
		}
	if (n <= 18) {
		do {
			int cnt = 0; //被拒绝的人数 
			int passed = 0; //通过的人数 
			for (int i = 1; i <= n; i ++) {
				if (cnt >= c[p[i]]) {
					cnt ++;
					continue;
				}
				if (a[i] == 1) {
					passed ++;
				} else cnt ++;
			}
			if (passed >= m) ans ++;
		} while (next_permutation(p + 1, p + n + 1));
		cout << ans << "\n";
		return 0;
	}
	if (m == n) {
		if (tagA == 0) return puts("0"), 0;
		int minc = 2e9, ans = 1;
		for (int i = 1; i <= n; i ++) minc = min(minc, c[i]), ans = ans * i % Mod;
		if (minc == 0) return puts("0"), 0;
		cout << ans << "\n";
		return 0;
	}
	if (m == 1) { //至少通过一人，反面是没有人通过 
		for (int i = 1; i <= n; i ++)
			for (int j = c[i]; j <= n; j ++) cnt[j] ++;
		int ans1 = 1, ans2 = 1;
		for (int i = 1; i <= n; i ++) ans1 = ans1 * i % Mod;
		for (int i = 1; i <= n; i ++) {
			if (cnt[i - 1] - (i - 1) <= 0) {
				ans2 = 0;
				break;
			}
			ans2 = ans2 * (cnt[i - 1] - (i - 1)) % Mod;
		}
		cout << (ans1 - ans2 + Mod) % Mod << "\n";
		return 0;
	}
	puts("0");
	fclose(stdin), fclose(stdout);
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3


Ren5Jie4Di4Ling5%
*/
