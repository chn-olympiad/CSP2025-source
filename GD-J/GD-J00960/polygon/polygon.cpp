#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7,mod=998244353;
ll n,arr[N],cnt;
void dfs(ll x,ll y,ll sum,ll mx){
	if(x==n+1){
		if(y>=3&&sum>mx*2)cnt=(cnt+1)%mod;
		return;
	}
	dfs(x+1,y+1,sum+arr[x],max(mx,arr[x]));
	dfs(x+1,y,sum,mx);
}
ll q(ll x,ll y){
	ll tmp=x,ans=1;
	while(y){
		if(y%2==1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		y/=2;
	}
	return ans;
}
ll get(ll x){
	if(x%2==0){
		x/=2;
		x=x*(x-1)%mod;
	}else{
		ll y=(x-1)/2;
		x=x*y%mod;
	}
	return x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
	if(n<=20){
		dfs(1,0,0,0);
		printf("%lld",cnt);
	}else{
		ll k=q(2,n);
		k=(k+mod-1)%mod;
		k=(k+mod-n)%mod;
		k=(k+mod-get(n))%mod;
		printf("%lld",k);
	}
	return 0;
} 
