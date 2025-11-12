#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5010;
LL n,ans,a[N],dp[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if(dp[2]>a[3]) ans=1;
	for(LL i=4;i<=n;i++){
		LL s=dp[i-1]-a[1];
		if(s>a[i])  ans=ans%998244353+1%998244353;
		if(dp[i-1]>a[i]) ans=ans%998244353+1%998244353;
		for(LL j=2;j<i;j++){
			if(dp[i-1]-a[j]>a[i]){
				ans=ans%998244353+1%998244353;
				if(s-a[j]>a[i]){
					ans=ans%998244353+1%998244353;
					s-=a[j];
				}
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
