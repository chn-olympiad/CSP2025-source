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
	const ll maxn=1e6+5,mod=993244853;
	ll n,q,has[maxn][2],bas=233,hast[2][maxn],pw[maxn],siz[maxn],tot;
	string s[2],t[2];
	vector<pll>rev[maxn];
	map<ll,ll>id;
	inline ll hash(ll op,ll l,ll r){
		return (hast[op][r]-hast[op][l-1]*pw[r-l+1]%mod+mod)%mod;
	}
	inline void sol1(){
		for(ll i=1;i<maxn;++i)pw[i]=pw[i-1]*bas%mod;
		for(ll i=1;i<=n;++i){
			cin>>s[0]>>s[1],siz[i]=s[0].size();
			for(ll j=0;j<siz[i];++j)has[i][0]=(has[i][0]*bas%mod+s[0][j])%mod;
			for(ll j=0;j<siz[i];++j)has[i][1]=(has[i][1]*bas%mod+s[1][j])%mod;
		}
		while(q--){
			cin>>t[0]>>t[1];
			if(t[0].size()!=t[1].size()){write(0);continue;}
			t[0]=" "+t[0],t[1]=" "+t[1];
			ll len=t[0].size();
			for(ll i=1;i<len;++i)hast[0][i]=(hast[0][i-1]*bas%mod+t[0][i])%mod;
			for(ll i=1;i<len;++i)hast[1][i]=(hast[1][i-1]*bas%mod+t[1][i])%mod;
			ll cnt=0;
			for(ll i=1;i<=n;++i){
				for(ll j=1;j+siz[i]-1<len;++j){
					if(hash(0,j,j+siz[i]-1)!=has[i][0]||hash(1,j,j+siz[i]-1)!=has[i][1])continue;
					cnt+=(hash(0,1,j-1)==hash(1,1,j-1)&&hash(0,j+siz[i],len-1)==hash(1,j+siz[i],len-1));
				}
			}
			write(cnt);
		}
	}
	struct ques{
		pll v;
		ll id;
	};
	vector<ques>p[maxn];
	ll ans[maxn],c[maxn];
	inline void upd(ll x,ll k){
		for(;x<maxn;x+=x&-x)c[x]+=k;
	}
	inline ll qry(ll x){
		ll res=0;
		for(;x;x-=x&-x)res+=c[x];
		return res;
	}
	inline void mian(){
		n=read(),q=read(),pw[0]=1;
		if(n<=1000&&q<=2000)sol1();
		else{
			for(ll i=1;i<=n;++i){
				cin>>s[0]>>s[1];
				ll pos0=0,pos1=0,len=s[0].size();
				for(ll j=0;j<len;++j)if(s[0][j]=='b'){pos0=j;break;}
				for(ll j=0;j<len;++j)if(s[1][j]=='b'){pos1=j;break;}
				if(!id.count(pos1-pos0))id[pos1-pos0]=++tot;
				ll now=id[pos1-pos0];
				rev[now].push_back({pos0,len-pos0+1});
			}
			for(ll i=1;i<=q;++i){
				cin>>t[0]>>t[1];
				if(t[0].size()!=t[1].size()){ans[i]=0;continue;}
				ll len=t[0].size(),pos0=0,pos1=0;
				for(ll j=0;j<len;++j)if(t[0][j]=='b'){pos0=j;break;}
				for(ll j=0;j<len;++j)if(t[1][j]=='b'){pos1=j;break;}
				if(!id.count(pos1-pos0)){ans[i]=0;continue;}
				ll now=id[pos1-pos0];
				p[now].push_back({{pos0,len-pos0+1},i});
			}
			for(ll i=1;i<=tot;++i){
				sort(rev[i].begin(),rev[i].end());
				sort(p[i].begin(),p[i].end(),[](ques a,ques b){
					return a.v<b.v;
				});
				ll j=0,k=0;
				while(k<p[i].size()){
					while(j<rev[i].size()&&rev[i][j].first<=p[i][k].v.first){
						upd(rev[i][j].second,1),++j;
					}
					ans[p[i][k].id]=qry(p[i][k].v.second),++k;
				}
				for(k=0;k<j;++k)upd(rev[i][k].second,-1);
			}
			for(ll i=1;i<=q;++i){
				write(ans[i]);
			}
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll t=1;
	while(t--)tobe::mian();
	return 0;
}