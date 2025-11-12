/*
T1.club
55 pts
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const int MaxN = 2e2;
const ll NInf = 0xc0c0c0c0c0c0c0c0;

int t;
	int n;
	int a[MaxN + 10][3 + 10];
	ll dp[MaxN + 10][MaxN + 10][MaxN + 10];
	ll ans;

void work_t () {
	scanf("%i", &n);
	for (int i = 1; i <= n; ++i) {scanf("%i%i%i", &a[i][1], &a[i][2], &a[i][3]);}
	memset(dp, 0xc0, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 1; i <= n/2; ++i) {dp[i][i][0] = dp[i - 1][i - 1][0] + a[i][1];}
	for (int i = 1; i <= n/2; ++i) {dp[i][0][i] = dp[i - 1][0][i - 1] + a[i][2];}
	for (int i = 1; i <= n/2; ++i) {dp[i][0][0] = dp[i - 1][0][0] + a[i][3];}
	for (int i = 1; i <= n; ++i) {for (int j = 1; j <= n/2 && j <= i; ++j) {dp[i][j][i - j] = max(dp[i - 1][j - 1][i - j] + a[i][1], dp[i - 1][j][i - j - 1] + a[i][2]);}}
	for (int i = 1; i <= n; ++i) {for (int j = 1; j <= n/2 && j <= i; ++j) {dp[i][j][0] = max(dp[i - 1][j - 1][0] + a[i][1], dp[i - 1][j][0] + a[i][3]);}}
	for (int i = 1; i <= n; ++i) {for (int j = 1; j <= n/2 && j <= i; ++j) {dp[i][0][i - j] = max(dp[i - 1][0][i - j] + a[i][3], dp[i - 1][0][i - j - 1] + a[i][2]);}}
	for (int i = 1; i <= n; ++i) {for (int j = 1; j <= n/2 && j <= i; ++j) {for (int k = 1; k <= n/2 && j + k <= i; ++k) {dp[i][j][k] = max(max(dp[i - 1][j - 1][k] + a[i][1], dp[i - 1][j][k - 1] + a[i][2]), dp[i - 1][j][k] + a[i][3]);}}}
	ans = NInf;
	for (int j = 1; j <= n/2; ++j) {for (int k = 1; k <= n/2; ++k) {if (n - j - k <= n/2) {ans = max(ans, dp[n][j][k]);}}}
	printf("%lli\n", ans);
}
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%i", &t);
	while (t--) {work_t();}
	return 0;
}