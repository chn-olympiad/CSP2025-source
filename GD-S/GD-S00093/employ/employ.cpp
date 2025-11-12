#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,t=1;
	char a;
	while(!isdigit(a=getchar()))t=a=='-'?-1:t;
	do{x=(x<<3)+(x<<1)+(a^48);}while(isdigit(a=getchar()));
	return x*t;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
const int N=5e2+5,mod=998244353;
inline ll qpow(ll x,ll m){
	ll ans=1;
	for(;m;m>>=1,x=x*x%mod)m&1?ans=ans*x%mod:0; 
	return ans;
}
int n,m,k,a[N],c[N],d[N];
ll pre[N],fac[N];
ll ans;
char s[N];
inline bool cmp(int a,int b){return a>b;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read(),fac[0]=1;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		d[i]=c[i]=read(),pre[i]=pre[i-1]+(s[i]^48),a[i]=i,fac[i]=fac[i-1]*i%mod;
	sort(d+1,d+n+1);
	if(pre[n]==114514){
		
		
	}else{
		do{
			int res=0,pos=0;
			for(int i=1;i<=n;i++){
				if(c[a[i]]<=res or s[i]=='0'){
					res++;
					continue;
				}
				if(i-res==m)pos=i+1;
			}
			if(n-res>=m){
				sort(a+pos,a+n+1,cmp);
				ans=(ans+fac[n-pos+1])%mod;
			}
			//cout << ans << "\n\n";
		}while(next_permutation(a+1,a+n+1));
	}
	write(ans);
	return 0;
}
