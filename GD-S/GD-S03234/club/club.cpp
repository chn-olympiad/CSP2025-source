#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[4][100010];
int dp[4][100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[1][i]>>a[2][i]>>a[3][i];
		for(int i=0;i<n;i++){
			if(i<n/2){
				int mm=max(dp[1][i-1],max(dp[2][i-1],dp[3][i-1]));
				dp[1][i]=mm+a[1][i];dp[2][i]=mm+a[2][i];dp[3][i]=mm+a[3][i];
			}else{
				dp[1][i]=max(dp[2][i-1],dp[3][i-1])+a[1][i];
				dp[2][i]=max(dp[1][i-1],dp[3][i-1])+a[2][i];
				dp[3][i]=max(dp[1][i-1],dp[2][i-1])+a[3][i];
			}
		}
		cout<<max(dp[1][n-1],max(dp[2][n-1],dp[3][n-1]))<<'\n';
	}
	return 0;
}
