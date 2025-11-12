#include <stdio.h>
#include <algorithm>
#include <map>]
#include <string.h>

using namespace std;

constexpr int MAXN = 205;
typedef long long ll; 
void Solve(); 
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while (T--) Solve();
	return 0;
}

#define reg register
#define FOR(i, a, b) for (reg int i = (a); i < (b); i++)
#define REP(i, a, b) for (reg int i = (a); i <= (b); i++)
int n;

const int q = 1e5 + 10;
int arr[q][4];
int dp[2][MAXN][MAXN][MAXN];
int tmp[q];

void Solve() {
	scanf("%d", &n);
	bool f = true;
	REP(i, 1, n) REP(j, 1, 3) scanf("%d", &arr[i][j]), f = (f && !arr[i][2] && !arr[i][3]);
	if (f) {
		REP(i, 1, n) tmp[i] = arr[i][1];
		sort(tmp + 1, tmp + 1 + n, greater<int>());
		
		int sum = 0;
		for (int i = 1; i <= n / 2; i++) sum += tmp[i];
		printf("%d\n", sum);
		return ;
	}
	
	REP(i, 1, n) {
		REP(j, 1, n)
			REP(k, 1, n) {
				int l = i - j - k;	
				dp[i % 2][j][k][l] = 0;
				if (j != n / 2) dp[i % 2][j][k][l] = max(dp[i % 2][j][k][l], dp[(i - 1) % 2][j - 1][k][l] + arr[i][1]);
				if (k != n / 2) dp[i % 2][j][k][l] = max(dp[i % 2][j][k][l], dp[(i - 1) % 2][j][k - 1][l] + arr[i][2]);
				if (l != n / 2) dp[i % 2][j][k][l] = max(dp[i % 2][j][k][l], dp[(i - 1) % 2][j][k][l - 1] + arr[i][3]); 
			}
	}
	
	int ans = 0;
	REP(i, 1, n) REP(j, 1, n) REP(k, 1, n) ans = max(ans, dp[0][i][j][k]);
	printf("%d\n", ans);
}
