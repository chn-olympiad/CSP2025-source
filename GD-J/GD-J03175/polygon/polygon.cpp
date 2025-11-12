#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define v first
#define sums second
using namespace std;
int n,dp[5005],ans,a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++){
		int k=1;
	   	for(int j=n;j>=n-i+1;j--)k*=j,k%=mod;
	   	for(int j=i;j>=1;j--) k/=j;
	   	ans+=k,ans%=mod;
	}
	if(n<3){
		cout<<0;
		return 0;	
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>(2*max(a[1],max(a[2],a[3]))))cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<ans%mod;
	return 0;
}
