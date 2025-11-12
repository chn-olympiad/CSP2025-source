#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const int mod=998244353;
int n,m,a[N],c[N];
ll jie[N],inv[N],ans;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
inline ll qpow(ll x,ll y){
	if(!y) return 1;
	ll ret=qpow(x,y/2);
	ret=ret*ret%mod;
	if(y&1) ret=ret*x%mod;
	return ret;
}
inline void solve1(){
	int w[n+1]={};
	for(int i=1;i<=n;i++) w[i]=i;
	do{
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!a[i] || (i-sum-1)>=c[w[i]]) continue;
			sum++;
		}
		if(sum>=m) ans++,ans%=mod;
	}while(next_permutation(w+1,w+n+1));
	printf("%lld",ans%mod);
}
inline ll C(int n,int m){
	return jie[n]*inv[m]%mod*inv[n-m]%mod;
}
inline void solve2(){
	sort(c+1,c+n+1);
	int sum=0,t=0;
	for(int i=1;i<=n;i++)
		if(c[i]<=sum) sum++;
		else{
			t=i-1;
			break;
		}
	if(m>=sum){
		printf("%lld",jie[n]%mod);
		return;
	}
	int tmp=sum-m;
	t=t-tmp+1;
	int temp=t-c[t];
	ans=jie[temp]*jie[t-temp]%mod*C(n-tmp,t-1)%mod;
	printf("%lld",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	jie[0]=jie[1]=1;
	for(int i=2;i<=n;i++) jie[i]=jie[i-1]*i%mod;
	inv[n]=qpow(jie[n],mod-2);
	for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++){
		char ch;
		cin >> ch;
		if(ch=='1') a[i]=1;
	}
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=20) solve1();
	else solve2();
	return 0;
}
