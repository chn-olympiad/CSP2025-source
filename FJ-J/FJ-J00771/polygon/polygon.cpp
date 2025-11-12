#include<bits/stdc++.h>
using namespace std;
long long const mod=998244353;
long long n,a[500005];
long long dp[5000*5002];
long long dp1[5000*5002];
long long mx=0;
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=a[1];i++) dp[i]=1;
	mx=a[1];
	for(int i=2;i<=n;i++){
		mx+=a[i];
		for(int j=mx;j>=1;j--){
			if(j<=a[i]){
				dp1[j]=1+dp[1];
				dp[j]+=1+dp[1];
			}
			else{
				dp1[j]=dp[j-a[i]];
				dp[j]+=dp[j-a[i]];
			} 
		}
		
		ans=(ans+dp1[a[i]*2+1])%mod;
	}
	cout<<ans; 
	return 0;
}
