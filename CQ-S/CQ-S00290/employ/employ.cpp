#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<ll,ll> pll;
using namespace std;
mt19937_64 rnd(time(0));
#define dbg(x) cout<<#x<<": "<<x<<'\n'
inline ll read(){ll x=0,f=1;char c=getchar();while(c<48||c>57)f^=(c==45),c=getchar();while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();return f?x:-x;}
inline void write(ll x){if(!x)return putchar(48),putchar('\n'),void();if(x<0)putchar(45),x=-x;char s[30],top=0;while(x)s[top++]=x%10^48,x/=10;while(top--)putchar(s[top]);putchar('\n');}
namespace tobe{
	const ll maxn=2e5+5,mod=998244353;
	ll n,m,c[maxn],ans;
	char s[maxn];
	bool vis[maxn];
	inline void dfs(ll dep,ll sum,ll alr){
		if(alr>=m)return ans=(ans+1)%mod,void();
		if(dep>n){
			if(n-sum>=m)ans=(ans+1)%mod;
			return;
		}
		for(ll i=1;i<=n;++i){
			if(vis[i])continue;
			vis[i]=1;
			if(s[dep]=='0')dfs(dep+1,sum+1,alr+1);
			else dfs(dep+1,sum+(sum>=c[i]),alr);
			vis[i]=0;
		}
	}
	inline void mian(){
		n=read(),m=read(),scanf("%s",s+1);
		for(ll i=1;i<=n;++i)c[i]=read();
		dfs(1,0,0),write(ans);
		return;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll t=1;
	while(t--)tobe::mian();
	return 0;
}