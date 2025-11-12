#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,ans,a[5005],s[5005],c[5005][5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
	sort(a+1,a+n+1);
	c[1][1]=1;
	for(int i=2;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	for(int i=3;i<=n;i++)ans=(ans+c[n+1][i+1])%mod;
	for(int i=1;i<n-1;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<=n;k++)if(a[i]+a[j]<=a[k]){
		ans-=(n-k+1);
		if(ans<0)ans+=mod;
		break;
	}
	for(int i=4;i<=n;i++)
		for(int k=i;k<=n;k++)
			if(s[k-1]-s[k-i]<=a[k]){
				cout<<"k="<<k<<",i="<<i<<","<<ans;
				ans-=(n-k+1);
				cout<<","<<ans<<endl;
				if(ans<0)ans+=mod;
				break;
			}
	printf("%lld",ans);
	return 0;
}
