#include<bits/stdc++.h>
using namespace std;
int a[1004];
int xor_[1004];
int dp[1004];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	xor_[0]=0;
	for(int i=1;i<=n;i++){
		xor_[i]=xor_[i-1]^a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i-1;j>=0;j--){
			int xx=xor_[i]^xor_[j];
			if(xx==m){
				dp[i]=max(dp[j]+1,dp[i]);
				break;
			}
		}
	}
	cout << dp[n];
	return 0;
}