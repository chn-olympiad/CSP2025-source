#include<bits/stdc++.h>
typedef int ll;
typedef long long ull;
typedef std::pair<ll,ll> pll;
using namespace std;
mt19937_64 rnd(time(0));
#define dbg(x) cout<<#x<<": "<<x<<'\n'
inline ll read(){ll x=0,f=1;char c=getchar();while(c<48||c>57)f^=(c==45),c=getchar();while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();return f?x:-x;}
inline void write(ull x){if(!x)return putchar(48),putchar('\n'),void();if(x<0)putchar(45),x=-x;char s[30],top=0;while(x)s[top++]=x%10^48,x/=10;while(top--)putchar(s[top]);putchar('\n');}
namespace tobe{
	const ll maxn=1e4+15,maxm=1e6+5,mod=998244353;
	ll n,m,k,c[11],a[11][maxn],pre[maxn],cnt;
	ull ans;
	struct edge{ll u,v,w;}e[maxm],tmp[maxm];
	inline ll find(ll x){return x==pre[x]?x:pre[x]=find(pre[x]);}
	inline void mian(){
		n=read(),m=read(),k=read();
		for(ll i=1;i<=m;++i)e[i]={read(),read(),read()};
		sort(e+1,e+m+1,[](edge a,edge b){
			return a.w<b.w;
		});
		for(ll i=1;i<=n;++i)pre[i]=i;
		for(ll i=1;i<=m;++i){
			ll u=find(e[i].u),v=find(e[i].v);
			if(u==v)continue;
			ans+=e[i].w,pre[u]=v;
			e[++cnt]=e[i];
		}
		for(ll i=1;i<=k;++i){
			c[i]=read();
			for(ll j=1;j<=n;++j)a[i][j]=read();
		}
		ll S=(1<<k)-1;
		for(ll s=1;s<=S;++s){
			ll top=cnt;
			ull now=0;
			for(ll i=1;i<=cnt;++i)tmp[i]=e[i];
			for(ll i=0;i<k;++i){
				if((s&(1<<i))==0)continue;
				now+=c[i+1];
				for(ll j=1;j<=n;++j){
					tmp[++top]={j,i+n+1,a[i+1][j]};
				}
			}
			for(ll i=1;i<=n+k;++i)pre[i]=i;
			sort(tmp+1,tmp+top+1,[](edge a,edge b){
				return a.w<b.w;
			});
			for(ll i=1;i<=top;++i){
				ll u=find(tmp[i].u),v=find(tmp[i].v);
				if(u==v)continue;
				now+=tmp[i].w,pre[u]=v;
			}
			ans=min(ans,now);
		}
		write(ans);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll t=1;
	while(t--)tobe::mian();
	return 0;
}