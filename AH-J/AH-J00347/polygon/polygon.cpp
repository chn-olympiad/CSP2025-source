#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const int mod=998244353;
int a[N];
ll dp[N*N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	int n;
	ll ans=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=dp[a[1]]=1,dp[a[2]]++,dp[a[1]+a[2]]++;
	sum=a[1]+a[2];
	for(int i=3;i<=n;i++){
		for(int j=sum+a[i];j>=a[i];j--){
			if(j<=sum&&j>a[i]) ans=(ans+dp[j])%mod;
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		sum+=a[i];
	}
	cout<<ans;
	return 0;
}
