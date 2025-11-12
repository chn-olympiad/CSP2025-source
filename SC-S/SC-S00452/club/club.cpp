#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Max_n = 1e5 + 10;
int a[Max_n][5];
int T, n, ans;
int dp[Max_n][5], vis[Max_n][5];
void dfs(int i, int sum, int aa, int b, int c){
	if(i == n+1){
		ans = max(ans, sum);
		return ;
	}
	if(aa+1 <= n/2){
		dfs(i+1, sum + a[i][1], aa+1, b, c);
	}
	if(b+1 <= n/2){
		dfs(i+1, sum + a[i][2], aa, b+1, c);
	}
	if(c+1 <= n/2){
		dfs(i+1, sum + a[i][3], aa, b, c+1);
	}
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
} 