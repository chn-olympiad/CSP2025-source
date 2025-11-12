#include<bits/stdc++.h>
using namespace std;
int n,z[5005];
long long dp[5005][5005];
long long ans=0;
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i];	
	}
	sort(z+1,z+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=z[i]+1;j<=z[n]+1;j++)ans+=dp[i-1][j];
		ans%=mod;
		for(int j=0;j<=z[n];j++){
			dp[i][j]=(j-z[i]>=0?dp[i-1][j-z[i]]:0)+dp[i-1][j];
			dp[i][j]%=mod;
		}
		long long te=0;
		for(int j=z[n]-z[i]+1;j<=z[n];j++)te+=dp[i-1][j];
		te+=dp[i-1][z[n]+1]*2;
		dp[i][z[n]+1]=te%mod;
	}
	cout<<ans;
	return 0;
}

