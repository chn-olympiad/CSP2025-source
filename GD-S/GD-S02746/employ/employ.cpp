#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
const int N = 105, mod = 998244353;

int n, k;
int s[N];
int c[N];

int m = 0;
struct Node {
	int val;
	int typ, id;
};
bool operator<(Node x, Node y) {
	if (x.val != y.val)
		return x.val < y.val;
	return x.typ < y.typ;
}
Node a[N * 2];

ll dp[N][N][N][N];
void add(ll &x, ll y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int main() {
	freopen("employ1.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%1d", &s[i]), s[i] = 1 - s[i];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		a[++m] = make_pair(c[i], 0);
	}
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1];
		a[++m] = make_pair(s[i], 1);
	}
	sort(a + 1, a + m + 1, [](pii x, pii y){return x.fi == y.fi ? x.se }); //01匹配，每出现一对10就加一分，求>=k分的方案数 
	for (int i = 1; i <= m; i++)
		printf("(%d,%d)", a[i].fi, a[i].se);
	puts("");
	dp[0][0][0][0] = 1; //dp[i][j][k]:前i个，余留j个0,k个1，得分为p的方案数 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= i; k++)
				for (int p = 0; p <= i / 2; p++)
					if (dp[i][j][k][p]) {
						//i+1是0
						if (a[i + 1].se == 0) {
							add(dp[i + 1][j + 1][k][p], dp[i][j][k][p]);
							if (k)
								add(dp[i + 1][j][k - 1][p + 1], dp[i][j][k][p]);
						}
						else {
							add(dp[i + 1][j][k + 1][p], dp[i][j][k][p]);
							if (j)
								add(dp[i + 1][j - 1][k][p], dp[i][j][k][p]);
						}
						
					}
	}
	
	ll ans = 0;
	for (int p = k; p <= m / 2; p++)
		add(ans, dp[m][0][0][p]);
	cout << ans << '\n';
	return 0;
}
