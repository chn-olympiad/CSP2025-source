//暴力 40分？？？
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+5;
ll n, k, a[N], dp[N][N];
ll ans;
bool vis[N];
void yuchuli() {
	for (int i = 1; i <= n; i++)
		dp[i][i] = a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int o = i; o <= j; o++)
				dp[i][j] ^= a[o];
}
bool check(int l, int r) {
	for (int i = l; i <= r; i++) {
		if (vis[i]) return 0;
		else vis[i] = 1;
	}
	return 1;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	yuchuli();
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if (dp[i][j] == k && check(i, j))
				ans++;
	cout << ans;
	return 0;
}