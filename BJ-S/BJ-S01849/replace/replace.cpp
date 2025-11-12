#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pub push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const int DC=0;
const ll mod=294998941;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
const ll inf=0x3f3f3f3f3f3f3f3f;

int n,q;
int ch[5000005][28],dfn[5000005],mxd[5000005],pcnt,dcnt;
map<ll,pii>rts;
int ins(string&s,int rt){
	int p=rt;
	for(auto c:s){
		if(!ch[p][c-96])ch[p][c-96]=++pcnt;
		p=ch[p][c-96];
	}
	return p;
}
void dfs(int now){
	dfn[now]=++dcnt;
	for(int i=1;i<=26;i++)if(ch[now][i])dfs(ch[now][i]);;
	mxd[now]=dcnt;
}
int qry(string&s,int rt){
	int p=rt;
	for(auto c:s){
		if(!ch[p][c-96])return p;
		p=ch[p][c-96];
	}
	return p;
}
struct nd{int t,l,r,v,id;};
vector<nd>ops;
pii pts[200005];
// bit
int s[5000005];
void add(int p,int v){for(;p<=pcnt;p+=p&-p)s[p]+=v;}
int qry(int p){int a=0;for(;p;p&=p-1)a+=s[p];return a;}
int ans[200005];

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(){
	cin>>n>>q;
	for(int _=1;_<=n;_++){
		string s,t;
		cin>>s>>t;
		if(s==t)continue;
		int l=s.size();
		int mn=l,mx=0;
		for(int i=0;i<l;i++)if(s[i]!=t[i]){
			mn=min(mn,i);
			mx=max(mx,i);
		}
		ll h1=0,h2=0;
		for(int i=mn;i<=mx;i++){
			h1=(h1*131+s[i])%mod;
			h2=(h2*131+t[i])%mod;
		}
		ll h=(h1<<32)|h2;
		if(!rts.count(h)){
			pcnt+=2;
			rts[h]={pcnt-1,pcnt};
		}
		string A="",C="";
		for(int i=0;i<mn;i++)A+=s[i];
		for(int i=mx+1;i<l;i++)C+=s[i];
		reverse(all(A));
		pts[_]={ins(A,rts[h].fi),ins(C,rts[h].se)};
	}
	for(auto[x,y]:rts)dfs(y.fi),dfs(y.se);
	for(int _=1;_<=n;_++)if(pts[_].fi){
		auto[x,y]=pts[_];
		ops.pub({dfn[x],dfn[y],mxd[y],1,0});
		ops.pub({mxd[x]+1,dfn[y],mxd[y],-1,0});
	}
	for(int _=1;_<=q;_++){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size())continue;
		int l=s.size();
		int mn=l,mx=0;
		for(int i=0;i<l;i++)if(s[i]!=t[i]){
			mn=min(mn,i);
			mx=max(mx,i);
		}
		ll h1=0,h2=0;
		for(int i=mn;i<=mx;i++){
			h1=(h1*131+s[i])%mod;
			h2=(h2*131+t[i])%mod;
		}
		ll h=(h1<<32)|h2;
		string A="",C="";
		for(int i=0;i<mn;i++)A+=s[i];
		for(int i=mx+1;i<l;i++)C+=s[i];
		reverse(all(A));
		pii tmp=rts[h];
		int x=qry(A,tmp.fi),y=qry(C,tmp.se);
		ops.pub({dfn[x],dfn[y],dfn[y],0,_});
	}
	sort(all(ops),[&](nd a,nd b){return a.t==b.t?a.id<b.id:a.t<b.t;});
	for(auto[t,l,r,v,id]:ops){
		if(v)add(l,v),add(r+1,-v);
		else ans[id]=qry(l);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	__INIT__();
	int T=0;DC?cin>>T,1:T=1;
	for(int c=1;c<=T;c++)__SOLVE__();
	return 0;
}