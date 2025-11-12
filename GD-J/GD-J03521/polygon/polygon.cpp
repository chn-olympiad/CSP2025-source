#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M=998244353,N=5e3+9;
int n,dp[N][N],a[N],s=1,ans=1; //s: begin with 1 (to exit empty set)

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int m=a[n];
	for(int i=1;i<=n;i++){
		dp[i][a[i]]=(1+dp[i][a[i]])%M;
		for(int j=1;j<=m;j++){
			if(!dp[i-1][j]) continue;
			if(j<=a[i]) s=(s+dp[i-1][j])%M;
			dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
			if(j+a[i]>m) continue;
			dp[i][j+a[i]]=(dp[i][j+a[i]]+dp[i-1][j])%M;
		}
	}
	for(int i=1;i<=n;i++) ans=(ans*2)%M; //all combinations
	ans=(ans-n)%M; //m=1 exit
	ans=(ans-s+M)%M; //less exit
	cout<<ans;
	return 0;
}
