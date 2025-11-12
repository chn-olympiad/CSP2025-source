#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001]={};
//int vis[5001] = {};
//int n , a[5001], sum = 0,ans=0;
//void dfs(int dp,int l){
//	if(dp > sum){
//		return;
//	}
//	if(l >= 3&& dp == 0){
//		ans++;
//		return;
//	}
//	for(int i = 0;i < n;i++){
//		if(a[i]*2 < dp&& vis[i] == 0){
//			vis[i] = 1;
//			dfs(dp-a[i],l++);
//			vis[i] = 0;
//		}
//	}
//	dfs(dp++,l);
//}
int main(){	
//	cin >> n;
//	for(int i = 0;i < n;i++){
//		cin >> a[i];
//		sum += a[i];
//	}int flag = 1;
//	for(int i = 0;i < n;i++){
//		if(a[i]!=1){
//			flag = 0;
//		}
//	}
//	if(flag == 1){
//		cout << n-2<<endl;
//		return 0;
//	}
//	dfs(0,0);
//	cout << ans;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n ,a[5001],sum = 0;
	cin >> n;
//	for(int i = 0;i <= n;i++){
//		for(int j = 0;j <= 1005;j++){
//			dp[i][j] = -1e9;
//		}
//	

	for(int i = 1;i <= n;i++){
		cin >> a[i];
		dp[1][a[i]] = 1;
		sum += a[i];
	}
	int flag = 1;
	for(int i = 1;i <= n;i++){
		if(a[i]!=1){
			flag = 0;
		}
	}
	if(flag == 1){
		cout << n-2<<endl;
		return 0;
	}
	sort(a,a+n+1);
	for(int j = 1; j <= sum;j++){
		for(int i = 1;i <= n;i++){
			if(a[i] < j){
				if(a[i]*2 < j && a[i] > dp[i-1][j-a[i]]){
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i]]+1);
				}
			}
			else{
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
			}
		} 
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1; j <= sum;j++){
//			cout << dp[i][j] << " "; 
//		} 
//		cout << endl;
//	}
	cout << dp[n][sum];
}
