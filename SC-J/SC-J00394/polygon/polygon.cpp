#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    long long s[6000] ,n,a[6000]={0},dp[6000]={0};cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=a[i-1]+a[i];
	if(max(a[1],max(a[2],a[3]))*2>s[3])dp[3]=1;
	if(n<=3){cout<<dp[n];
		return 0;
	}
	long long ans=0;
    for(int i=3;i<=n;i++){
    	long long s=1,p=1;
    	for(int j=1;j<=i;j++){
    		s*=j;p*=(n-j+1);
		}
		ans+=(p/s+ans)%mod;
	}
	
 cout<<ans;
	return 0;
}