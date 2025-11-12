#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],dp[N][N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[1][0]=2;
	for(int i=1;i<=a[1];i++) dp[1][i]++;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=a[n]+1;j++){
			dp[i][j]=(dp[i-1][j]*2)%mod;
			dp[i][j]=(dp[i][j]+dp[i-1][max(j-a[i],0)]-dp[i-1][j])%mod;
		}
	}
	for(int i=1;i<=n;i++){
		ans=(ans+dp[i-1][a[i]+1])%mod;
	}
	cout<<ans<<'\n';
	return 0;
}