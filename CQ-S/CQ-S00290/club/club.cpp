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
	const ll maxn=1e5+5,mod=998244353;
	ll n,a[maxn][4],ans,less[maxn];
	priority_queue<pll>q[4];
	inline void mian(){
		n=read(),ans=0;
		for(ll i=1;i<=3;++i){
			while(!q[i].empty())q[i].pop();
		}
		for(ll i=1;i<=n;++i){
			ll mx=0;
			for(ll j=1;j<=3;++j){
				a[i][j]=read();
				if(a[i][j]>a[i][mx])mx=j;
			}
			ans+=a[i][mx],less[i]=0;
			for(ll j=1;j<=3;++j){
				if(j==mx)continue;
				if(less[i]<a[i][j])less[i]=a[i][j];
			}
			q[mx].push({less[i]-a[i][mx],i});
		}
		ll big=0;
		for(ll i=1;i<=3;++i){
			if(q[i].size()>q[big].size())big=i;
		}
		while(q[big].size()>n/2){
			ans+=q[big].top().first;q[big].pop();
		}
		write(ans);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t=read();
	while(t--)tobe::mian();
	return 0;
}