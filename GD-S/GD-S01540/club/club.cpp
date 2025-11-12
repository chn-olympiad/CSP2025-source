#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 210;

struct Node {
	int q, w, e;
} a[N];

int dp[M][M][M];

inline bool kp_a (Node a, Node b) {
	return a.q > b.q;
}

int t, n;

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	while (t --) {
		memset (dp, 0, sizeof (dp));
		scanf ("%d", &n);
		int i2 = 0, i3 = 0;
		for (int i = 1; i <= n; i ++) {
			scanf ("%d%d%d", &a[i].q, &a[i].w, &a[i].e);
			i2 += a[i].w;
			i3 += a[i].e;
		}
		if (!i2 && !i3) {
			sort (a + 1, a + 1 + n, kp_a);
			int ans = 0;
			for (int i = 1; i <= n / 2; i ++) {
				ans += a[i].q;
			}
			cout << ans << '\n';
			continue;
		} else {
			int u = n / 2;
			dp[1][0][0] = a[1].q;
			dp[0][1][0] = a[1].w;
			dp[0][0][1] = a[1].e;
			int ans = 0;
			for (int i = 2; i <= n; i ++) {
				for (int j = 0; j <= i; j ++) {
					for (int k = 0; k + j <= i; k ++) {
						int p = i - j - k;
						if (j) dp[j][k][p] = max (dp[j - 1][k][p] + a[i].q, dp[j][k][p]);
						if (k) dp[j][k][p] = max (dp[j][k - 1][p] + a[i].w, dp[j][k][p]);
						if (p) dp[j][k][p] = max (dp[j][k][p - 1] + a[i].e, dp[j][k][p]);
						if (i == n & j <= u && k <= u && p <= u) {
							ans = max (ans, dp[j][k][p]);
						}
					}
				}
			}
			cout << ans << '\n';
			continue;
		}
		
	}
	return 0;
} 

/*
期望得分：
14:40 O(3^n) 20
15:09 O(n^3) + A 60

*/

/*
Play note (?)
I can 3^n baoli!!!
I find it can dp
dp[i][j][k] => 3 clubs' numbers
and I can get 55 pts!! So high!!
And special A is so easy that I can get 5 more pts
5 + 55 = 60
Oh yeah!
Sleep~
*/
