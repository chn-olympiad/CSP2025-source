#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=5010,mod=998244353;
int n;
int a[N],dp[N][N],f[N][N];
int main(){
//	freopen("polygon1.in","r",stdin);
//	freopen("polygon1.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][5001]=dp[i-1][5001];
		for(int j=max(0,5001-a[i]);j<=5001;j++){
			dp[i][5001]=(dp[i][5001]+dp[i-1][j])%mod;
		}
		f[i][5001]=dp[i][5001];
		for(int j=5000;j>=0;j--){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
			f[i][j]=(f[i][j+1]+dp[i][j])%mod;
//			cout<<dp[i][j]<<' ';
		}
//		cout<<dp[i][5001];
//		cout<<endl;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ans=(ans+f[j-1][a[i]-a[j]+1])%mod;
		}
	}
	cout<<ans;
	return 0;
}
