#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353,N=5010;
ll n,cnt,ans,a[N],jc[N];
int main(){
	freopen("polygon.in","r",stdin); freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){scanf("%lld",&a[i]); if(a[i]==1) cnt++;}
	if(n==3){//1~3≤‚ ‘µ„ 
		ll ma=0,res=0;
		for(ll i=1;i<=n;i++){res+=a[i]; ma=max(ma,a[i]);}
		if(res>2*ma) ans=1;
	}else if(cnt==n){//15~20≤‚ ‘µ„ 
		ans=jc[1]=1; jc[2]=n*(n-1)/2;
		for(int i=3;i<=n-1;i++) ans=(ans+jc[i-1]*(n-i+1)/2)%mod;
	} printf("%lld",ans%mod); return 0;
}
