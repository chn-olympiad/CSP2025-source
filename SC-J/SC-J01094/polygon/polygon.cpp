#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar('0'+sta[top--]);
}
const int mod=998244353;
const int N=5005;
ll n,a[N],p[N],ans,inv[N],fac[N];
inline ll C(ll n,ll m){
	if(n<0||m<0||n<m)return 0;
	return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
void dfs(int last,int now,int lim){
	if(now>lim){
		ll mx=0,sum=0;
		for(int i=1;i<=lim;i++){
			mx=max(mx,a[p[i]]);
			sum+=a[p[i]];
		}
		if(mx*2<sum){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		p[now]=i;
		dfs(i,now+1,lim);
	}
}
inline ll TLE(ll x,ll k){
	ll ret=1;
	while(k){
		if(k&1)ret=ret*x%mod;
		x=x*x%mod;k>>=1;
	}
	return ret;
}
inline void init(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=5000;i++)fac[i]=fac[i-1]*i%mod;
	inv[5000]=TLE(fac[5000],mod-2);
	for(int i=4999;i;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n<=50){
		for(int i=3;i<=n;i++)dfs(0,1,i);
		write(ans);
		return 0;
	}
	init();
	for(int i=3;i<=n;i++)ans=(ans+C(n,i))%mod;
	write(ans);
	return 0;
}
/*

*/