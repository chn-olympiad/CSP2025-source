#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e3+233,N=1e8+233,mod=998244353;
ll n,v[M],t[N],mx,ans,can[N];
int lowbit(int x){
	return x&(-x);
}
void update(int x,ll v){
	for(int i=x;i<=mx;i+=lowbit(i))
		t[i]=(t[i]+v)%mod;
	return;
}
ll check(int x){
	ll res=0;
	for(int i=x;i;i-=lowbit(i))
		res=(res+t[i])%mod;
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
		mx+=v[i];
	}
	mx++;
	sort(v+1,v+1+n); 
	can[0]=1;
	for(int i=1;i<=n;i++){
		ans=(ans+check(mx)-check(v[i]))%mod;
		for(int j=mx;j>=0;j--){
			if(can[j]){
				ll t=min(mx,j+v[i]);
				can[t]=(can[t]+can[j])%mod;
				update(t,can[j]);
			}
		}
	}
	printf("%lld",ans%mod);
	return 0;
}
