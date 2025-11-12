#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
int n, a[5010], b[5010];
ll ans, f[5010][5010];

void dfs(int i, int cnt, int sum, int maxn){
	if(i > n){
		if(cnt >= 3 && sum > 2 * maxn) ans ++, ans %= mod;
		return;
	}
	dfs(i + 1, cnt + 1, sum + a[i], max(maxn, a[i]));
	dfs(i + 1, cnt, sum, maxn);
}

void calc(){
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++){
		f[i][0] = f[i][i] = 1;
		for(int j = 1; j < i; j ++)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; int maxn = 0;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], maxn = max(maxn, a[i]);
	if(maxn == 1){
		calc();
		for(int i = 3; i <= n; i ++)
			ans += f[n][i], ans %= mod;
		cout << ans;
		return 0;
	}
	ans = 0;
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}
