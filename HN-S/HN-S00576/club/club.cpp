#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
vector <int> a[N];
int dp[N][4], g[N][4][4];
bool cmp(vector <int> a, vector <int> b){
	return max(a[1], max(a[2], a[3])) > max(b[1], max(b[2], b[3]));
}
int ans = 0;
void dfs(int step, int t1, int t2, int t3, int sum){
	if(step > n){
		ans = max(ans, sum);
		return ;
	}
	if(t1 < n / 2) dfs(step + 1, t1 + 1, t2, t3, sum + a[step][1]);
	if(t2 < n / 2) dfs(step + 1, t1, t2 + 1, t3, sum + a[step][2]);
	if(t3 < n / 2) dfs(step + 1, t1, t2, t3 + 1, sum + a[step][3]);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; cin >> t;
	for(int i = 1; i < N; i ++) a[i].resize(4);
	while(t --){
		cin >> n;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= 3; j ++){
				cin >> a[i][j];
			}
		}
		if(n <= 30){
			ans = 0;
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
			continue;
		}
		else{
			sort(a + 1, a + n + 1, cmp);
			memset(dp, 0, sizeof dp);
			memset(g, -0x3f, sizeof g);
			for(int i = 1; i <= 3; i ++){
				for(int j = 1; j <= 3; j ++){
					g[0][i][j] = 0;
				}
			} 
			for(int i = 1; i <= n; i ++){
				for(int j = 1; j <= 3; j ++){
					for(int k = 1; k <= 3; k ++){
						if(g[i - 1][j][k] < n / 2){
							if(dp[i - 1][j] + a[i][k] > dp[i][k]){
								dp[i][k] = dp[i - 1][j] + a[i][k];
								g[i][k][k] = g[i - 1][j][k] + 1;
								int t = k + 1;
								if(t == 4) t = 1;
								g[i][k][t] = g[i - 1][j][t];
								t ++;
								if(t == 4) t = 1;
								g[i][k][t] = g[i - 1][j][t];
							}
							
						}
					}
				}
				for(int j = 1; j <= 3; j ++){
					for(int k = 1; k <= 3; k ++){
						if(g[i][j][k] < -1000000000){
							g[i][j][k] = g[i - 1][j][k];
						}
					}
				}
			}
			cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << "\n";	
		}
	}
	return 0;
} 
