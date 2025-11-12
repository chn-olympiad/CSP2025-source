#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
#define md 998244353
ll n,a[N],dp[N],ans;
const long long mx=5000;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=mx+1;j++) ans=(ans+dp[j])%md; 
		for(int j=mx+1;j>=mx+1-a[i];j--) dp[mx+1]=(dp[mx+1]+dp[j])%md;
		for(int j=mx;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%md;
	}	
	printf("%lld\n",ans);
	return 0;
}
