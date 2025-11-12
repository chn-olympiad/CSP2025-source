#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int t, n;
int arr[N][4];
int C[4];
int tot;
int dp[210][210][210];
struct node{
	int id, ned;
}peo[N];
int ans = 0;
bool cmp(node a, node b){
	return a.ned > b.ned;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		memset(C, 0 , sizeof(C));
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		tot = n / 2;
		for(int i = 1; i <= n; i++){
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= tot; j++){
				for(int k = 0; k <= tot; k++){
//					if(j + k > i) break;
//					if(!dp[i][j][k]) continue;
					int l = i - j - k;
					if(j + k + l > i)break;
//					cout <<i << ": " << j << " " << k << " " << l << endl;
					if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + arr[i][1]);
//					cout << dp[i][j][k] << endl;
					if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + arr[i][2]);
//					cout << dp[i][j][k] << endl;
					if(l > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + arr[i][3]);
					ans = max(ans, dp[i][j][k]);
//					cout << dp[i][j][k] << endl;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
