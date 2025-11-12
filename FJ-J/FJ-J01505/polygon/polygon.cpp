#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
long long dp[N+5][N+5];
long long g[N+5][N+5];
long long a[N+5];
long long pow_mod[N+5];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	pow_mod[0]=1;
	for(int i=1;i<=5002;i++){
		pow_mod[i]=pow_mod[i-1]*2%mod;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	sort(a+1,a+n+1);
	long long ans=0;
	dp[0][0]=1;
	for(int j=1;j<n;j++){
		for(int k=a[j];k<=a[n];k++){
			dp[j][k]=(dp[j-1][k-a[j]]%mod+dp[j-1][k]%mod)%mod;
		}
		for(int k=0;k<a[j];k++){
			dp[j][k]=dp[j-1][k]%mod;
		}
		for(int k=1;k<=a[n];k++){
			g[j][k]=(g[j][k-1]+dp[j][k])%mod;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<i;j++){
			ans+=((g[j-1][a[i]]-g[j-1][a[i]-a[j]])%mod+mod)%mod*pow_mod[i-j-1]%mod;
			ans%=mod;
		}
	}
	cout<<ans%mod<<"\n";
	return 0;
}
