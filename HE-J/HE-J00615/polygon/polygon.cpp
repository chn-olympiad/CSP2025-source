#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,mod=998244353;
ll n,m,a[N],sum[N],jc[N]={1};
ll ans;
ll arsum(int l,int r){
	return sum[r]-sum[l-1];
}
ll qpow(int p,int q){
	if(q==1) return p;
	if(q==0) return 1;
	ll tmp=qpow(p,q>>1)%mod;
	if(q&1) return p*tmp%mod%tmp%mod;
	return tmp*tmp%mod;
	
}
ll C(int p,int q){
	return jc[q]*qpow(p,q-2)%mod*qpow(q-p,q-2)%mod;
}
void dfs(ll sum,ll pp,int cur,int pos,int num){
	if(num==0){
		ans+=(sum>pp*2);
		ans%=mod;
		return;
	}
	for(int i=cur+1; i<=pos; i++){
		dfs(a[i]+sum,pp,i,pos,num-1);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=N; i++) jc[i]=jc[i-1]*i%mod;
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	for(int len=3; len<=n; len++){
		for(int i=len; i<=n; i++)
			dfs(0,a[i],0,i,len);
	}
	cout<<ans;
	return 0;
}

