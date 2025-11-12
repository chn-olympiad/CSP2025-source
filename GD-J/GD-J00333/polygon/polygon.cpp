#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,sum[5050],max5000,ans,a[5050];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1),sum[0]=1;
	for(int i=1;i<=n;i++){
		ans+=max5000,max5000=(max5000*2)%mod;
		for(int j=a[i]+1;j<=5000;j++) ans+=sum[j],ans%=mod;
		for(int j=5000;j>=0;j--) {
			if(j+a[i]>5000) max5000=(max5000+sum[j])%mod;
			else sum[j+a[i]]=(sum[j+a[i]]+sum[j])%mod;
		}
	}cout<<ans;
}
