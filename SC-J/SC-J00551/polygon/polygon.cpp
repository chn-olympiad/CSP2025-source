#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e3+5,mod=998244353;
int a[N],n,cnt[5005],ma=-1;
ll dp[N][N],ans=0;
ll qp(int x,int y){
	ll res=1,base=x;
	while(y){
		if(y&1)res=res*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+1+n);
	memset(dp,0,sizeof dp);
	dp[2][a[1]+a[2]]=1;
	++cnt[a[1]];
	++cnt[a[2]];
	for(int i=3;i<=n;i++){
		for(int j=0;j<=ma;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+dp[i-1][j]+cnt[j-a[i]])%mod;
			}
		}
		cnt[a[i]]++;
	}
	for(int i=3;i<=n;i++){
		ll res=qp(2,i-1)-i;
		for(int j=0;j<=a[i];j++){
			res=res-dp[i-1][j];
		}
		ans=(ans+res)%mod;
	}
	while(ans<0)ans+=mod;
	ans=ans%mod;
	cout<<ans;
	return 0;
}
/*1 Nov 2025
鎴戣j浠ユ潵鏈€绠€鍗曠殑
娼甸崚鏉跨岸寮剁捄銊ュ笧厔挎稑濂旂粭鍌氣枎闄
*/