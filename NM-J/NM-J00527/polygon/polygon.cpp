#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5010];
long long dp[5010][5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
			dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
		}
	}
	cout<<dp[1][n]%mod;
	return 0;
}
