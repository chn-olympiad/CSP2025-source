#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, dp[205][205][205];
struct node{
	int x, y, z;
}a[N];
void solve(){
	cin >> n;
	bool flag = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		if(a[i].y || a[i].z) flag = 0;
	}
	if(flag){
		sort(a + 1, a + n + 1, [](node x, node y){
			return x.x > y.x;
		});
		int ans = 0;
		for(int i = 1; i <= n / 2; i++)
			ans += a[i].x;
		cout << ans << "\n";
		return ;
	}
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k <= i; k++){
				int x = n / 2;
				if(j > x || k > x || i - j - k > x) continue;
				dp[i][j][k] = dp[i - 1][j][k];
				if(j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i].x);
				if(k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i].y);
				if(i - j - k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i].z);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n / 2; i++)
		for(int j = 0; j <= n / 2; j++){
			if(n - i - j > n / 2) continue;
			ans = max(ans, dp[n][i][j]);
		}
	cout << ans << "\n";
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
//60pts
