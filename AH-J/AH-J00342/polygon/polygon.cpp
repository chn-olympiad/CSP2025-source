#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],dp[25000000],cnt[25000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		b[i]=b[i-1]+a[i];
	//	dp[a[i]]=1;
	}
	dp[0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=b[i];j>=a[i];j--)  dp[j]=(dp[j]+dp[j-a[i]])%998244353;
	}
	
	//for(int i=1;i<=n;i++) dp[a[i]]--;
	//for(int i=2;i<=n;i++) {
	//	for(int j=1;j<i;j++) dp[a[i]+a[j]]--;
//}
	for(int i=1;i<=n;i++) {
		for(int j=a[i]*2;j>=1;j--) dp[j]=(dp[j]-dp[j-a[i]])%998244353;
	}
	
	for(int i=1;i<=b[n];i++) cnt[i]=(max(0,dp[i])+cnt[i-1])%998244353;
	int ans=0;
	for(int i=3;i<=n;i++) ans=(ans+(cnt[b[i]]-cnt[a[i]*2]))%998244353;
	cout<<ans;
	return 0;
}
