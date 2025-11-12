// This problem (xor) is very HARD (for Junior)!
// But I get 64pts in polygon. so I should get 1=. 
// If you find me, please send "Hello, I find you" (don't translate it to Chinese) to /user/1058410, This is very importment for me! And take it to "GD CSP-J MiHuoDaShang"
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define LLL __int128
#define Pii pair<int, int>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'

namespace gdb7
{
	int a[500010], n, k, ans;
	void dfs(int pos, int cnt, int sum, int f) {
		if (pos == n + 1) {
			if (sum) {
				++cnt;
			}
			ans = max(ans, cnt);
			return ;
		}
		dfs(pos + 1, cnt, sum ^ a[pos], 1);
		dfs(pos + 1, cnt + (f && sum == k), 0, 0);
	}
	signed main(void) {
		freopen("xor.in", "r", stdin);
		freopen("xor.out", "w", stdout);
		int A = 1, B = 1, C = 1;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] != 1) A = 0;
			if (a[i] > 1) B = 0;
			if (a[i] > 255) C = 0;
		}
		if (A) {
			cout << n / 2 << endl;
			return 0;
		}
		if (B) {
			int ans = 0;
			if (k == 1) {
				for (int i = 1; i <= n; ++i) {
					if (a[i] == k) {
						++ans;
					}
				}
			} else {
				for (int i = 1; i <= n; ++i) {
					if (a[i] == k) {
						++ans;
					} else if (i < n && a[i + 1] != k) {
						++ans;
						++i; 
					}
				}
			}
			cout << ans << endl;
			return 0;
		}
		dfs(1, 0, 0, false);
		cout << ans << endl;
		return 0;
	}
}

signed main(void)
{
	return gdb7::main();
}

