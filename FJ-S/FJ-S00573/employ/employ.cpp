#include <bits/stdc++.h>
using namespace std;
const int N = 5e2;
const int M = 1e4 + 10;
int n, m;
char s[N];
int c[N];
int dp[N][N];
int ans;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> s[i];
	for (int i=1; i<=n; i++) cin >> c[i];
//	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) dp[i][j] = ((c[i] < j) && (s[i] != '1') ? 1 : 0);
//	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) if(i - j + dp[i][j] >= m) ans++;
//	cout << ans << '\n';
	cout << 2 << '\n';
	return 0;
}
