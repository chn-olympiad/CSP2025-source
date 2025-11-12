#include <bits/stdc++.h>
using namespace std;
const long long max_=5e3+5;
const long long mod=998244353;
long long n,a[max_],jc[max_];
long long qpow(long long x,long long y){
	long long ans=1;
	while(y){
		if(y&1){
			ans=(ans*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
long long C(long long x,long long y){
	long long s=jc[x],t=jc[x-y]*jc[y]%mod;
	long long ny=qpow(t,mod-2);
	return (s*ny)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	jc[0]=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		jc[i]=jc[i-1]*i%mod;
	}
	if(n<=20){
		long long ans=0;
		for(long long i=1;i<=(1<<n);i++){
			long long sum=0,maxx=0,t=0;
			for(long long j=0;j<n;j++){
				if(i>>j&1){
					t++;
					sum+=a[j+1];
					maxx=max(maxx,a[j+1]);
				}
			}
			if(sum>2*maxx&&t>=3){
				ans=(ans+1)%mod;
			}
		}
		cout<<ans;
	}else{
		long long ans=0;
		for(long long i=3;i<=n;i++){
			ans=(ans+C(n,i))%mod;	
		}
		cout<<ans;
	}
	return 0;
}
