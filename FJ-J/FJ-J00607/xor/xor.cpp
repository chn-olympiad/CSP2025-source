#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5; 
int dp[N][N];
int n,k,x,a[N],ans1,ans2;
int main( ){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for(int i=n;i>=1;i--){
		if(dp[i][i]==k){
			ans1++;
			continue;
		}
		for(int j=i-1;j>=1;j--){
			dp[j][i]=dp[j+1][i]^dp[j][j];
			if(dp[j][i]==k){
				i=j;
				ans1++;
				break;
			}
		}
	}
	for(int i=1;i<n;i++){
		if(dp[i][i]==k){
			ans2++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			dp[i][j]=dp[i][j-1]^dp[j][j];
			if(dp[i][j]==k){
				i=j;
				ans2++;
				break;
			}
		}
	}
	cout<<max(ans1,ans2);
	return 0;
}

