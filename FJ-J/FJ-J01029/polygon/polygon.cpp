#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5005];
long long dp[5005];
long long qp(long long a,int b){
	if(a<=1||b==1)
		return a;
	if(b==0)
		return 1;
	long long res=1;
	while(b){
		if(b&1)
			res=(res*a+mod)%mod;
		a=(a*a+mod)%mod;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(i<=2){
			for(int j=5000-a[i];j>=0;j--){
				dp[j+a[i]]+=dp[j];
				dp[j+a[i]]=(dp[j+a[i]]+mod)%mod;
			}
			continue;
		}
		ans+=qp(2*1ll,i-1);
		ans=(ans+mod)%mod;
		for(int j=0;j<=a[i];j++){
			ans-=dp[j];
			ans=(ans+mod)%mod;
		}
		for(int j=5000-a[i];j>=0;j--){
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]=(dp[j+a[i]]+mod)%mod;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
