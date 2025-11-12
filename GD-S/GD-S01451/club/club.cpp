#include<bits/stdc++.h>
using namespace std;
const int N=210;
int n,a[100010][3],dp[N][N][N],t,c[100010];//到第i人，部门1有j人，部门2有k人 
void solve(){
	int ans=0;
	memset(dp,0,sizeof dp);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i][0]>>a[i][1]>>a[i][2];
	if(n>200){
		int ans=0;
		for(int i=1;i<=n;++i) c[i]=a[i][0];
		sort(c+1,c+1+n,greater<int>());
		for(int i=1;i<=n/2;++i) ans+=c[i];
		return;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=min(i,n/2);++j){
			for(int k=0;k<=min(i-j,n/2);++k){
//				cout<<i<<' '<<j<<' '<<k<<"bbb\n";
				if(i-j-k>n/2) continue;
				if(i!=j+k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
				if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][0]);
				if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][1]);
//				dp[i][j][k]=max(max(dp[i-1][j-1][k]+a[i][0],dp[i-1][j][k-1]+a[i][1]),dp[i-1][j][k]+a[i][2]);
				if(i==n) ans=max(ans,dp[i][j][k]);
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<"aaa\n";
			}
		}
	}
//	for(int i=1;i<=n;++i,cout<<endl)
//		for(int j=0;j<=n;++j,cout<<endl)
//			for(int k=0;k<=n;++k)
//				cout<<dp[i][j][k]<<' ';
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
}
