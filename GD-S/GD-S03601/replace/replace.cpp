bool Mst;
#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using ll=long long;
using ull=unsigned long long;
using i128=__int128;
using u128=__uint128_t;
using pii=pair<int,int>;
#define fi first
#define se second
constexpr int N=2e5+5,B=632,NN=5e6+5,mod=998244353;
inline ll add(ll x,ll y){return (x+=y)>=mod&&(x-=mod),x;}
inline ll Add(ll &x,ll y){return x=add(x,y);}
inline ll sub(ll x,ll y){return (x-=y)<0&&(x+=mod),x;}
inline ll Sub(ll &x,ll y){return x=sub(x,y);}
inline ll qpow(ll a,ll b){
	ll res=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)res=res*a%mod;
	return res;
}
int n,m,p0[N],p1[N],to0[NN],to1[NN],c0,c1;
struct ACAM{
	int idx,t[NN][26],fail[NN],qu[NN],l,r;
	int dep[NN],dfc,L[NN],R[NN];
	struct edge{int y,pre;}Gr[NN];int Grlen,last[NN];
	inline void ins(int x,int y){Gr[++Grlen]={y,last[x]},last[x]=Grlen;}
	inline int ins(const string &s){
		int p=0;
		for(const auto &o:s){
			int c=o-'a';
			if(!t[p][c])
				t[p][c]=++idx,dep[t[p][c]]=dep[p]+1;
			p=t[p][c];
		}
		return p;
	}
	inline void dfs(int x){
		L[x]=++dfc;
		for(int k=last[x],y;y=Gr[k].y,k;k=Gr[k].pre)
			dfs(y);
		R[x]=dfc;
	}
	inline void build(){
		l=0,r=-1;
		for(int i=0;i<26;i++)
			if(t[0][i])
				qu[++r]=t[0][i],fail[t[0][i]]=0;
		while(l<=r){
			int p=qu[l++],o=fail[p];
			ins(o,p);
			#define wk(c) (!t[p][c]?t[p][c]=t[o][c]:fail[qu[++r]=t[p][c]]=t[o][c])
			wk(0),wk(1),wk(2),wk(3),wk(4),wk(5),wk(6),wk(7),wk(8),wk(9),
			wk(10),wk(11),wk(12),wk(13),wk(14),wk(15),wk(16),wk(17),wk(18),wk(19),
			wk(20),wk(21),wk(22),wk(23),wk(24),wk(25);
		}
		dfs(0);
	}
}F0,F1;
struct node{
	int x,l,r,v;
	node(){x=l=r=v=0;}
	node(int _x,int _l,int _r,int _v){x=_x,l=_l,r=_r,v=_v;}
};
node mdf[N<<1],qry[NN<<1],tmp[NN<<1];int lm,lq;
int cnt[N<<1];
int tot,pos[N<<1],L[N<<1],R[N<<1];
int s0[N<<1],s1[N<<1];
inline void upd(int x,int v){
	if(x>c1)return;
	int o=pos[x];
	for(int i=x;i<=R[o];i++)s0[i]+=v;
	for(int i=o;i<=tot;i++)s1[i]+=v;
}
inline int ask(int x){
	if(!x)return 0;
	return s0[x]+s1[pos[x]-1];
}
inline int ask(int l,int r){
	return ask(r)-ask(l);
}
ll ans[N];
bool Med;
int main(){
	cerr<<abs(&Mst-&Med)/1048576.0<<endl;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s0,s1;cin>>s0>>s1;
		p0[i]=F0.ins(s0),p1[i]=F1.ins(s1);
	}
	F0.build(),F1.build();
	for(int i=1;i<=n;i++){
		to0[F0.L[p0[i]]]=to0[F0.R[p0[i]]+1]=1;
		to1[F1.L[p1[i]]]=to1[F1.R[p1[i]]+1]=1;
	}
	for(int i=1;i<=F0.dfc+1;i++)to0[i]+=to0[i-1];
	for(int i=1;i<=F1.dfc+1;i++)to1[i]+=to1[i-1];
	for(int i=1;i<=n;i++){
		int l0=to0[F0.L[p0[i]]],r0=to0[F0.R[p0[i]]+1];
		int l1=to1[F1.L[p1[i]]],r1=to1[F1.R[p1[i]]+1];
		mdf[++lm]=node(l0,l1,r1,1);
		mdf[++lm]=node(r0,l1,r1,-1);
	}
	
	for(int _=1;_<=m;_++){
		string t0,t1;cin>>t0>>t1;
		if(t0.size()!=t1.size()){
			ans[_]=0;
			continue;
		}
		int len=t0.size(),l=0,r=0;
		for(int i=0;i<len;i++)
			if(t0[i]!=t1[i]){
				l=i;
				break;
			}
		for(int i=len-1;i>=0;i--)
			if(t0[i]!=t1[i]){
				r=i;
				break;
			}
		int p=0,tp=0,q=0,tq=0;
		for(int i=0;i<len;i++){
			int u=t0[i]-'a',v=t1[i]-'a';
			p=F0.t[p][u],tp=F0.t[tp][u];
			q=F1.t[q][v],tq=F1.t[tq][v];
			if(i>=r){
				while(F0.dep[tp]>=i-l+1)tp=F0.fail[tp];
				while(F1.dep[tq]>=i-l+1)tq=F1.fail[tq];
				if(p==tp||q==tq)continue;
				int l0=to0[F0.L[tp]],r0=to0[F0.L[p]];
				int l1=to1[F1.L[tq]],r1=to1[F1.L[q]];
				qry[++lq]=node(l0,l1,r1,-_);
				qry[++lq]=node(r0,l1,r1,_);
			}
		}
	}
	
	c0=to0[F0.dfc+1],c1=to1[F1.dfc+1];
	
	for(int i=1;i<=c0;i++)cnt[i]=0;
	for(int i=1;i<=lm;i++)++cnt[mdf[i].x];
	for(int i=1;i<=c0;i++)cnt[i]+=cnt[i-1];
	for(int i=lm;i>=1;i--)tmp[cnt[mdf[i].x]--]=mdf[i];
	for(int i=1;i<=lm;i++)mdf[i]=tmp[i];
	
	for(int i=1;i<=c0;i++)cnt[i]=0;
	for(int i=1;i<=lq;i++)++cnt[qry[i].x];
	for(int i=1;i<=c0;i++)cnt[i]+=cnt[i-1];
	for(int i=lq;i>=1;i--)tmp[cnt[qry[i].x]--]=qry[i];
	for(int i=1;i<=lq;i++)qry[i]=tmp[i];
	
	while(R[tot]<c1){
		++tot;
		L[tot]=R[tot-1]+1;
		R[tot]=min(c1,L[tot]+B-1);
		for(int i=L[tot];i<=R[tot];i++)
			pos[i]=tot;
	}
	node o;
	for(int i=1,j=1;i<=lq;i++){
		while(j<=lm&&mdf[j].x<=qry[i].x)
			o=mdf[j++],upd(o.l,o.v),upd(o.r,-o.v);
		o=qry[i];
		if(o.v>0)
			ans[o.v]+=ask(o.l,o.r);
		else
			ans[-o.v]-=ask(o.l,o.r);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}
