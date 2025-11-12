#include<bits/stdc++.h>
using namespace std;
int a[10000];
int dp[5005][4][5005];
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			dp[i][1][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			for(int k=0;k<=mx;k++){
				dp[i][j][k]+=dp[i-1][j][k];
				dp[i][j][k]%=mod;
				if(k<=a[i]){
					dp[i][j][k]+=dp[i-1][j-1][0];
				}
				else{
					dp[i][j][k]+=dp[i-1][j-1][k-a[i]];
				}
				dp[i][j][k]%=mod;
				dp[i][0][k]=dp[i][1][k];
				dp[i][0][k]%=mod;
			}
		}
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=dp[i-1][2][a[i]];
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 
