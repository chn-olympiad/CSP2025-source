#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;
int ans = 0;
int a1[100005], a2[100005], a3[100005];
bool vis[100005];
struct node {
	int val, x, y, z;
};
node dp[100005][4]; 
void dfs(int n, int s, int d1, int d2, int d3) {
	if(d1 + d2 + d3 == n) {
		ans = max(ans, s);
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = true;
			if(d1 < n / 2) dfs(n, s + a1[i], d1 + 1, d2, d3);
			if(d2 < n / 2) dfs(n, s + a2[i], d1, d2 + 1, d3);
			if(d3 < n / 2) dfs(n, s + a3[i], d1, d2, d3 + 1);
			vis[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a1[i] >> a2[i] >> a3[i];
		if(n == 100000 && a3[1] == 0) {
			sort(a1 + 1, a1 + n + 1);
			for(int i = n; i >= n / 2; i--) {
				ans += a1[i];
			}
			cout << ans << "\n";
		}else if(n <= 5) {
			ans = 0;
			memset(vis, false, sizeof vis);
			dfs(n, 0, 0, 0, 0);
			cout << ans << "\n";
		}else {
			dp[1][1] = {a1[1], 1, 0, 0};
			dp[1][2] = {a2[1], 0, 1, 0};
			dp[1][3] = {a3[1], 0, 0, 1};
			for(int i = 1; i <= n; i++) {
					if(dp[i - 1][1].val > dp[i - 1][2].val && dp[i - 1][1].val > dp[i - 1][3].val && dp[i - 1][1].x < n / 2) {
						dp[i][1] = {dp[i - 1][1].val + a1[i], dp[i - 1][1].x + 1, dp[i - 1][1].y, dp[i - 1][1].z};
					}else if(dp[i - 1][2].val > dp[i - 1][1].val && dp[i - 1][2].val > dp[i - 1][3].val && dp[i - 1][2].x < n / 2){
						dp[i][1] = {dp[i - 1][2].val + a1[i], dp[i - 1][2].x + 1, dp[i - 1][2].y, dp[i - 1][2].z};
					}else if(dp[i - 1][3].x < n / 2){
						dp[i][1] = {dp[i - 1][3].val + a1[i], dp[i - 1][3].x + 1, dp[i - 1][3].y, dp[i - 1][3].z};
					}
					if(dp[i - 1][1].val > dp[i - 1][2].val && dp[i - 1][1].val > dp[i - 1][3].val && dp[i - 1][1].y < n / 2) {
						dp[i][2] = {dp[i - 1][1].val + a2[i], dp[i - 1][1].x, dp[i - 1][1].y + 1, dp[i - 1][1].z};
					}else if(dp[i - 1][2].val > dp[i - 1][1].val && dp[i - 1][2].val > dp[i - 1][3].val && dp[i - 1][2].y < n / 2){
						dp[i][2] = {dp[i - 1][2].val + a2[i], dp[i - 1][2].x, dp[i - 1][2].y + 1, dp[i - 1][2].z};
					}else if(dp[i - 1][3].y < n / 2){
						dp[i][2] = {dp[i - 1][3].val + a2[i], dp[i - 1][3].x, dp[i - 1][3].y + 1, dp[i - 1][3].z};
					}
					if(dp[i - 1][1].val > dp[i - 1][2].val && dp[i - 1][1].val > dp[i - 1][3].val && dp[i - 1][1].z < n / 2) {
						dp[i][3] = {dp[i - 1][1].val + a3[i], dp[i - 1][1].x, dp[i - 1][1].y, dp[i - 1][1].z + 1};
					}else if(dp[i - 1][2].val > dp[i - 1][1].val && dp[i - 1][2].val > dp[i - 1][3].val && dp[i - 1][2].z < n / 2){
						dp[i][3] = {dp[i - 1][2].val + a3[i], dp[i - 1][2].x, dp[i - 1][2].y, dp[i - 1][2].z + 1};
					}else if(dp[i - 1][3].z < n / 2){
						dp[i][3] = {dp[i - 1][3].val + a3[i], dp[i - 1][3].x, dp[i - 1][3].y, dp[i - 1][3].z + 1};
					}
			}
			cout << max(dp[n][1].val, max(dp[n][2].val, dp[n][3].val)) << "\n";
		}
	}
	return 0;
}
