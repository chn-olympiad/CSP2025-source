#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long ans=0;
	char c;
	c=getchar();
	while(c<'0' or c>'9')c=getchar();
	while(c>='0' && c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
long long n,a[5555],dp[5555][5555],mod=998244353,ans,sum=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++){
		sum=(sum*2)%mod;
		dp[i-1][0]=1;
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=5000;j++){
			if(j>=a[i]){
				dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
			}
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=a[i];j++){
			ans=(ans+dp[i-1][j])%mod;
		}
	}
	cout<<(sum-ans-1+mod+mod)%mod;
	return 0;
}
