#include <cstdio>
#include <algorithm>
#include <initializer_list>
int Ch;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
inline void r(char&x){while((x=getchar())<33);}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
using ll=long long;
constexpr int N=510,M=998244353;
int n,m,i,j,k,l,x,a[N],t[N],vis[N],p[N],cnt[N],pre[N];
ll fac[N],inv[N],invfac[N],f[N][N],g[N][N],ans;
char ch;
inline ll A(const int n,const int m){return fac[n]*invfac[n-m]%M;}
inline ll C(const int n,const int m){return fac[n]*invfac[n-m]%M*invfac[m]%M;}
template<typename T>
inline void add(T&x,const T&y){x=(x+y)%M;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	r(n,m);
	*fac=*invfac=1;
	for(i=1;i<=n;i++){
		r(ch);
		t[i]=ch&1;
		fac[i]=fac[i-1]*i%M;
		inv[i]=i>1?inv[M%i]*(M-M/i)%M:1;
		invfac[i]=invfac[i-1]*inv[i]%M;
	}
	for(i=1;i<=n;i++){
		r(a[i]);
		cnt[a[i]]++;
	}
	std::sort(a+1,a+n+1);
	x=k=0;
	for(i=0;i<=n;i++)pre[i]=cnt[i];
	for(i=1;i<=n;i++){
		pre[i]+=pre[i-1];
		if(t[i]){
			for(j=1;j<=n;j++)if(a[j]>x&&!vis[j])break;
			if(j<=n){
				p[i]=j;
				k++;
			}
		}
		if(!p[i]){
			x++;
			for(j=1;j<=n;j++)if(!vis[j])break;
			p[i]=j;
		}
	}
	if(k<m){
		w(0);
		return 0;
	}
	f[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<i;j++){
			for(k=0;k<i;k++){
				g[j][k]=f[j][k];
				f[j][k]=0;
			}
		}
		if(t[i]){
			for(j=0;j<i;j++){
				for(k=0;k<i;k++){
					if(!g[j][k])continue;
					add(f[j][k+1],g[j][k]);
					for(l=0;l<=cnt[j+1]&&l<=k;l++){
						add(f[j+1][k-l],g[j][k]*C(k,l)%M*A(cnt[j+1],l)%M*(pre[j]-(i-1-k)));
					}
				}
			}
		}
		else{
			for(j=0;j<i;j++){
				for(k=0;k<i;k++){
					if(!g[j][k])continue;
					for(l=0;l<=cnt[j+1]&&l<=k;l++){
						add(f[j+1][k-l],g[j][k]*C(k,l)%M*A(cnt[j+1],l)%M*(pre[j+1]-(i-1-(k-l))));
						add(f[j+1][k-l+1],g[j][k]*C(k,l)%M*A(cnt[j+1],l)%M);
					}
				}
			}
		}
	}
	x=n;
	for(i=0;i+m<=n;i++){
		x-=cnt[i];
		ans=(ans+f[i][x]*fac[x])%M;
	}
	w(ans);
	return 0;
}