#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 18, mod = 992844353;
int n, m;
string s;
int p[N+5];
int dp[1<<N][N+5];
int ans; 

int Getpos(int sta) {
	int p = 0;
	while (sta) p++, sta ^= sta & -sta;
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> p[i];
	dp[0][0] = 1;
	for (int sta = 0; sta < (1<<n); sta++) {
		int pos = Getpos(sta);
		for (int k = 0; k < n; k++) {
			for (int i = 1; i <= n; i++) {
				if (!(sta >> (i-1) & 1)) {
//					cout << sta << ',' << k << ' ' << s[pos] << ' ' << dp[sta][k] << "->";
					int x = sta ^ (1 << (i-1)), y = k + (p[i] <= k || s[pos] == '0');
//					cout << x << ',' << y << '\n';
					dp[x][y] = (dp[x][y] + dp[sta][k]) % mod;
				}
			}
		}
	}
	for (int i = 0; i <= n-m; i++) ans = (ans + dp[(1<<n) - 1][i]);
	cout << ans;
	return 0;
}
/*
挣扎已无意义。 
*/
