#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct matr{
	int fi, se, th, maxn;
}a[N];
struct node{
	int sum, one, two, three;
}dp[N][4];
bool cmp(matr x, matr y){
	return x.maxn > y.maxn;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++) dp[i][j] = {0, 0, 0, 0};
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i].fi >> a[i].se >> a[i].th;
			a[i].maxn = max(max(a[i].fi, a[i].se), a[i].th);
		}
		sort(a + 1, a + n + 1, cmp);
		dp[1][1] = {a[1].fi, n / 2 - 1, n / 2, n / 2};
		dp[1][2] = {a[1].se, n / 2, n / 2 - 1, n / 2};
		dp[1][3] = {a[1].th, n / 2, n / 2, n / 2 - 1};
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				if(dp[i - 1][j].one > 0){
					if(dp[i - 1][j].sum + a[i].fi > dp[i][1].sum){
						dp[i][1] = {dp[i - 1][j].sum + a[i].fi, dp[i - 1][j].one - 1, dp[i - 1][j].two, dp[i - 1][j].three};
					} 
				}
			}
			for(int j = 1; j <= 3; j++){
				if(dp[i - 1][j].two > 0){
					if(dp[i - 1][j].sum + a[i].se > dp[i][2].sum){
						dp[i][2] = {dp[i - 1][j].sum + a[i].se, dp[i - 1][j].one, dp[i - 1][j].two - 1, dp[i - 1][j].three};
					}
				}
			}
			for(int j = 1; j <= 3; j++){
				if(dp[i - 1][j].three > 0){
					if(dp[i - 1][j].sum + a[i].th > dp[i][3].sum){
						dp[i][3] = {dp[i - 1][j].sum + a[i].th, dp[i - 1][j].one, dp[i - 1][j].two, dp[i - 1][j].three - 1};
					}
				}
			}
		}
		for(int i = 1; i <= 3; i++) ans = max(ans, dp[n][i].sum);
		cout << ans << '\n';
	}
	return 0;
} 
