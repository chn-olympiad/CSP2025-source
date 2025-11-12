#include <iostream>
#include <algorithm>
#define MAXN (5010)
#define MOD (998244353)

using namespace std;
typedef long long LL;
int n, m;
int a[MAXN];

LL sum[MAXN];
LL dp[MAXN][MAXN];

bool vis[MAXN];
void DP0(int s, int suml, int g, int ai) {
	if (g < 3) return ;
	if (suml > ai * 2) {
		dp[s][g] = (dp[s][g] + 1 % MOD);
//		if (s == 5) {
//			for (int i = 1; i <= s; i++)
//				if (!vis[i]) cout << a[i] << " ";
//			cout << "\n";	
//		}
	}
	for (int i = s - 1; i >= 1; i--) {
		if (vis[i]) continue;
		vis[i] = true; 
		DP0(s, suml - a[i], g - 1, ai);
		vis[i] = false;
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	
	for (int i = 3; i <= n; i++) {
		DP0(i, sum[i], i, a[i]);
	}
	
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			ans = (ans + dp[i][j]) % MOD;
	}

    cout << flush;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
