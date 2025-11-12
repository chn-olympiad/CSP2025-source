#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool b[250001];
long long n,a[5001],sum[501],ans,s=1,f[225252],dp[250001]={1},o[225252],e[225252],p[5001]={1};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=s;j>0;j--){
			if(!b[f[j]+a[i]]) dp[f[j]+a[i]]+=dp[f[j]],b[f[j]+a[i]]=1,f[++s]=f[j]+a[i];
			else o[++c]=f[j]+a[i],e[c]=dp[f[j]];
			if(f[j]>a[i]) ans=(ans+dp[f[j]])%mod;
		}
		for(int j=1;j<=c;j++) dp[o[j]]=(dp[o[j]]+e[j])%mod;
	}
	cout<<ans;
}
