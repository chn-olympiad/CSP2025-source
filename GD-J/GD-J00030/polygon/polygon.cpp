#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5005;
const ll mod=998244353;
int a[maxn],n;
ll ans;
ll qpow(ll n,ll m){
	ll res=1;
	while(m){
		if(m&1) res=res*n%mod;
		n=n*n%mod,m>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool is=0;
	for(int i=1;i<=n;++i) scanf("%d",a+i),is|=(a[i]>1);
	sort(a+1,a+n+1);
	if(!is){
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				ans=(ans+qpow(2,n-j)-1)%mod;
		if(ans<0) ans+=mod; 
		printf("%lld",ans);
		return 0; 
	}
	int m=(1<<n);
	for(int x=0;x<m;++x){
		int mx=0,sum=0;
		for(int i=1;i<=n;++i){
			if(x&(1<<(i-1))) sum+=a[i],mx=max(mx,a[i]);
		}
		if(sum>(mx<<1)) ++ans;
	}
	printf("%lld",ans);
	return 0;
}
