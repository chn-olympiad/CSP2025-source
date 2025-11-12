#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T&x){
	x=0; char c; int sign=1;
	do{c=getchar(); if(c=='-') sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	x*=sign;
}
const ll mod=998244353;
ll n,k,a[5010];
ll ans,ansn;
bool flag=true;
void dfs(int s,int k,int cnt,ll sum,ll maxn){
	if(s==cnt){ 
		if(sum>maxn*2){
			ans=(ans+1)%mod;
		} 
		return;
	}
	for(int i=k+1;i<=n;i++){
		dfs(s,i,cnt+1,sum+a[i],max(maxn,a[i]));
	}
	return;
}
ll p[5010];
void solv(int x){
	p[1]=1; p[2]=2; p[3]=6; p[4]=24;
	for(int i=5;i<=x;i++){
		p[i]=(p[i-1]*i)%mod;
	}
	return;
}
ll qpow(ll a,ll b){
	ll su=1;
	while(b){
		if(b&1){
			su=(su*a)%mod;
		}
		b>>=1;
		a=(a*a)%mod;
	}
	return su;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]!=1) flag=false;
	} 
	if(flag){
		solv(n);
		for(int i=3;i<n;i++){
			ll r=qpow((p[n-i]*p[i])%mod,mod-2);
			ansn=(ansn+(p[n]*r)%mod)%mod;
		}
		cout<<ansn+1;
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			dfs(i,j,1,a[j],a[j]);
		}
	}
	cout<<ans;
	return 0;
} 

