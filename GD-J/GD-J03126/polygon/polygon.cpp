#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {k=(k<<1)+(k<<3)+ch-48;ch=getchar();}
	return k*f;
}
int n;
const int N=5007;
const ll mod=998244353;
int a[N],s[N],now=1,lst=0;
ll f[N],g[N*N],ans;
ll qpow(ll a,ll b){
	ll bas=a,ans=1;
	while(b){
		if(b&1) ans=ans*bas%mod;
		bas=bas*bas%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	g[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++)
			(f[i]+=g[j])%=mod;
		for(int j=min(a[n],s[i-1]);j>=0;j--)
			(g[j+a[i]]+=g[j])%=mod;
	}
	ll sum=qpow(2,n);
	for(int i=1;i<=n;i++) (ans+=f[i])%=mod;
	printf("%lld",(sum-ans+mod-1)%mod);
	return 0;
} 
