//2024tysc0092 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[5005],s[5005],pw[5005],dp[5005][10005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	pw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*2%998244353;
	}
	if(a[1]+a[2]>a[n]){
		cout<<pw[n];
		return 0;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		for(int j=0;j<=min(s[i-1],a[n]*2+1);j++){
			dp[i][j]=(dp[i][j]+dp[i-1][j])%998244353;
			dp[i][min(j+a[i],a[n]*2+1)]=(dp[i][min(j+a[i],a[n]*2+1)]+dp[i-1][j])%998244353;
			if(j>a[i]){
				ans=(ans+dp[i-1][j])%998244353;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
TLE&&MLE&&WA&&RE&&UKE¤Îdp 
*/
