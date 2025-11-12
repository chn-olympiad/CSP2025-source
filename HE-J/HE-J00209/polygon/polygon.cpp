#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5100;
const int mod=998244353;
int n;
int a[N];
int sum[N];
int dp[N][N][4];
//int h[N][N];//h[s][i] 到 i 用2个以上组成 0~s 的总方案数 
signed main(){
//	freopen("polygon3.in","r",stdin);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[a[i]][j][1]++;
			dp[a[i]][j][1]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int s=0;s<=sum[i];s++){
			if(s>a[i]){
				dp[s][i][2]+=dp[s-a[i]][i-1][1];
				dp[s][i][2]%=mod;
				dp[s][i][3]+=dp[s-a[i]][i-1][2]+dp[s-a[i]][i-1][3];
				dp[s][i][3]%=mod; 
			}
			dp[s][i][2]+=dp[s][i-1][2];
			dp[s][i][2]%=mod;
			dp[s][i][3]+=dp[s][i-1][3];
			dp[s][i][3]%=mod;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int s=sum[i];s>=1;s--){
//			cout<<i<<" "<<s<<" "<<dp[s][i][1]<<" "<<dp[s][i][2]<<" "<<dp[s][i][3]<<endl;
//		}
//	}
	for(int i=3;i<=n;i++){
		for(int s=a[i]+1;s<=sum[i-1];s++){
			ans+=dp[s][i-1][2];
			ans%=mod;
			ans+=dp[s][i-1][3];
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
