#include<bits/stdc++.h>
using namespace std;
const long long N=5005,mod=998244353;
long long n,m,dal=1,ans,a[N],f[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;++i)cin>>a[i];
	for(long long i=1;i<=n;++i)m=max(a[i],m);
	sort(a+1,a+n+1);
	f[0]=1;
	for(long long i=1;i<=n;++i){
		long long s=0;
		for(long long j=0;j<=a[i];++j)s=(s+f[j])%mod;
		for(long long j=m;j>=a[i];--j)f[j]=(f[j]+f[j-a[i]])%mod;
		ans=(ans+dal-s+mod*2)%mod;
		dal=dal*2%mod;
	}
	cout<<ans<<"\n";
	return 0;
}

