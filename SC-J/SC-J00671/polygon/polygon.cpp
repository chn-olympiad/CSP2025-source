#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long dp[3][10015][2];//I DON'T WANNA MLE AND 0PTS 
long long mod=998244353ll,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	dp[0][0][0]=1;
//	for(long long j=0;j<=25;j++){
//		cout<<dp[0][j]<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<n;i++){
		int nt=1-i%2,on=i%2;
		memset(dp[nt],0,sizeof(dp[nt]));
		for(int j=0;j<=10001;j++){
			dp[nt][min(10001ll,j+a[i+1])][1]+=dp[on][j][0]+dp[on][j][1];
			dp[nt][min(10001ll,j+a[i+1])][1]%=mod;
			dp[nt][j][0]+=dp[on][j][0]+dp[on][j][1];
			dp[nt][j][0]%=mod;
		}
		for(int j=a[i+1]*2+1;j<=10001;j++){
			ans+=dp[nt][j][1];
			ans%=mod;
		}
//		for(long long j=0;j<=25;j++){
//			if(j==a[i+1]*2+1){
//				cout<<" | ";
//			}
//			cout<<dp[nt][j]<<' ';
//		}
//		cout<<endl;
	}
	cout<<ans<<endl;
}