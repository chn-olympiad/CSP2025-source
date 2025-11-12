#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define her1 20081214
#define IV void
#define cht 998244353
#define ull unsigned long long
#define mem(x,val) memset(x,val,sizeof x)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#undef ll
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
using i64 = int;
using i128 = __int128_t;
const int maxn = 2e5+5;
const int maxm = 5e6+5;
const long long M = 1000000016000000063ll;

i64 n,q;
char s[maxm],t[maxm];

i64 nxt[maxm][26],tot,dft;
i64 first[maxm],csp=1,dfn[maxm],low[maxm];
struct edge{i64 to,nxt;}e[maxm];
IV add(i64 u,i64 v){
	e[++csp]={v,first[u]};
	first[u]=csp;
}
i64 ins(i64 L){
	i64 now=0;
	D(i,L,1){
		if(!nxt[now][s[i]-'a']){
			nxt[now][s[i]-'a']=++tot;
			add(now,nxt[now][s[i]-'a']);
		}
		now=nxt[now][s[i]-'a'];
	}
	return now;
}
IV dfs(i64 u){
	dfn[u]=++dft;
	E(i,u)dfs(e[i].to);
	low[u]=dft;
}
IV Build(){
	dfs(0);
}

i64 v1[maxn],v2[maxn];
i64 q1[maxn],q2[maxn];

struct BIT{
	i64 c[maxm],qwq[maxm],tot,ans;bool vis[maxm];
	IV clr(){
		F(i,1,tot)c[qwq[i]]=vis[qwq[i]]=0;
		tot=0;
	}
	IV add(i64 p,i64 v){
		for(;p<=dft;p+=p&-p){
			if(!vis[p])vis[qwq[++tot]=p]=1;
			c[p]+=v;
		}
	}
	i64 Q(i64 p){ans=0;for(;p;p-=p&-p)ans+=c[p];return ans;}
	IV add(i64 l,i64 r,i64 v){add(l,v);add(r+1,-v);}
}bit;
long long Ans[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	vector<array<long long,5> >V;
	F(o,1,n){
		scanf("%s%s",s+1,t+1);
		i64 L=strlen(s+1);
		i64 p1=0,p2=0;
		F(i,1,L)if(s[i]!=t[i]){
			p2=i;
			if(!p1)p1=i;
		}
		i64 s1=0,s2=0;
		F(k,p1,p2){
			s1=(i128(s1)*131+s[k]-'a')%M;
			s2=(i128(s2)*131+t[k]-'a')%M;
		}
		v1[o]=s1;
		v2[o]=s2;
		// cout<<p1-1<<' '<<L-p2<<endl;
		i64 a=ins(p1-1);
		reverse(s+1,s+1+L);
		i64 b=ins(L-p2);
		// cout<<a<<' '<<b<<endl;
		V.push_back({s1,s2,a,b,0});
	}
	Build();
	// cout<<tot<<endl;
	// F(i,0,tot)cout<<dfn[i]<<' '<<low[i]<<endl;

	F(o,1,q){
		scanf("%s%s",s+1,t+1);
		i64 L=strlen(s+1);
		if(L!=strlen(t+1))
			continue;
		i64 p1=0,p2=0;
		F(i,1,L)if(s[i]!=t[i]){
			p2=i;
			if(!p1)p1=i;
		}
		i64 s1=0,s2=0;
		F(k,p1,p2){
			s1=(i128(s1)*131+s[k]-'a')%M;
			s2=(i128(s2)*131+t[k]-'a')%M;
		}
		q1[o]=s1;
		q2[o]=s2;

		i64 a=0,b=0;
		D(i,p1-1,1)if(nxt[a][s[i]-'a'])a=nxt[a][s[i]-'a'];else break;
		F(i,p2+1,L)if(nxt[b][s[i]-'a'])b=nxt[b][s[i]-'a'];else break;
		V.push_back({s1,s2,a,b,o});
	}
	sort(V.begin(),V.end());
	for(int l=0,r;l<V.size();l=r+1){
		r=l;
		while(r+1<V.size()&&get<0>(V[r+1])==get<0>(V[r])&&get<1>(V[r+1])==get<1>(V[r]))
			r++;
		bit.clr();
		vector<array<i64,4> >nw;
		F(t,l,r){
			auto[x,y,p,q,id]=V[t];
			if(!id){
				nw.push_back({dfn[p],0,q,1});
				nw.push_back({low[p]+1,0,q,-1});
			}
			else{
				nw.push_back({dfn[p],id,q,0});
			}
		}
		sort(nw.begin(),nw.end());
		for(auto[x,id,q,w]:nw){
			// cout<<"add"<<dfn[q]<<' '<<low[q]<<' '<<w<<endl;
			if(!id)bit.add(dfn[q],low[q],w);
			else Ans[id]=bit.Q(dfn[q]);
		}
	}
	
	F(o,1,q)printf("%lld\n",Ans[o]);
	return 0;
}