#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],dp[25000005],ldp[25000005],sum,ans;
const long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	ldp[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=a[i]+1;j<=sum;j++){
				ans+=ldp[j];
				ans%=mod;
			}
		}
		for(int j=0;j<=sum;j++){
			dp[j]=ldp[j];
		}
		for(int j=0;j<=sum;j++){
			dp[j+a[i]]+=ldp[j];
			dp[j]%=mod;
		}
		sum+=a[i];
		for(int j=0;j<=sum;j++){
			ldp[j]=dp[j];
		}
	}
	cout<<ans;
	return 0;
}
