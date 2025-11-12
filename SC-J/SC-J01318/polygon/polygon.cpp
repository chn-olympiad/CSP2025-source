#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],b[5005],c[5005],ans;
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	b[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]*i)%mod;
	}
	c[n+1]=1;
	for(int i=n;i>=1;i--){
		c[i]=(c[i+1]*i)%mod;
	}
	for(int i=3;i<=n;i++){
		ans=(ans+c[n-i+1]/b[i])%mod;
	}
	cout<<ans;
	return 0;
}