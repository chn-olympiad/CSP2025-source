#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define MP make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define ep emplace
#define eb emplace_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
bool Mbe;

template<typename T>void chkmin(T&x,T y){if(y<x)x=y;}
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}

char buf[1<<20],*p1,*p2;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++
int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')f^=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')s=s*10+c-'0',c=getchar();
	return f?s:-s;
}

const int N=200005,M=5000005,V=26*26;
int n,Q,tot,rt1[M],cur;
char s[M],t[M];
pii vec[V+5];
struct SGT1{
	int ls[M*22],rs[M*22],val[M*22],totn;
	void upd(int l,int r,int p,int v,int&u,int pre){
		u=++totn;ls[u]=ls[pre],rs[u]=rs[pre],val[u]=val[pre];
		if(l==r)return val[u]=v,void();
		int mid=(l+r)>>1;
		if(mid>=p)upd(l,mid,p,v,ls[u],ls[pre]);
		else upd(mid+1,r,p,v,rs[u],rs[pre]);
	}
	void build(int l,int r,int&u,int d){
		u=++totn;
		int mid=(l+r)>>1;
		build(l,mid,ls[u],d+1);
		build(mid+1,r,rs[u],d+1);
	}
	int qry(int l,int r,int p,int u){
		if(!u)return 0;
		if(l==r)return val[u];
		int mid=(l+r)>>1;
		if(mid>=p)return qry(l,mid,p,ls[u]);
		return qry(mid+1,r,p,rs[u]);
	}
	void get(int l,int r,int u){
		if(!u)return;
		if(l==r)return vec[++cur]=MP(l,val[u]),void();
		int mid=(l+r)>>1;
		get(l,mid,ls[u]);
		get(mid+1,r,rs[u]);
	}
}sgt1;
int q[M],hd=1,tl,ed[M],fa[M][20],fail[M],dep[M];

bool Med;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fprintf(stderr,"%.3lfMb\n",(&Mbe-&Med)/1024./1024.);
	n=read(),Q=read();
	while(n--){
		char ch=getchar();
		int len=0,now=0;
		while(ch>='a'&&ch<='z')s[++len]=ch,ch=getchar();
		ch=getchar(),len=0;
		while(ch>='a'&&ch<='z')t[++len]=ch,ch=getchar();
		rep(i,1,len){
			int c=(s[i]-'a')*26+(t[i]-'a')+1;
			int v=sgt1.qry(1,V,c,rt1[now]);
			if(!v){
				sgt1.upd(1,V,c,++tot,rt1[now],rt1[now]);
				now=tot,dep[now]=i;
			}else now=v;
		}
		ed[now]++;
	}
	cur=0,sgt1.get(1,V,rt1[0]);
	rep(i,1,cur)q[++tl]=vec[i].se;
	while(hd<=tl){
		int u=q[hd++];
		cur=0,sgt1.get(1,V,rt1[u]);
		rt1[u]=rt1[fail[u]];
		rep(i,1,cur){
			int x=vec[i].fi,y=vec[i].se;
			fail[y]=sgt1.qry(1,V,x,rt1[u]);
			sgt1.upd(1,V,x,y,rt1[u],rt1[u]);
			q[++tl]=y;
		} 
	}
	rep(i,1,tot){
		int u=q[i];
		fa[u][0]=fail[u],ed[u]+=ed[fail[u]];
		rep(j,1,19){
			fa[u][j]=fa[fa[u][j-1]][j-1];
			if(!fa[u][j])break;
		}
	}
	while(Q--){
		char ch=getchar();
		int len=0,now=0,L=0,R=0;
		while(ch>='a'&&ch<='z')s[++len]=ch,ch=getchar();
		ch=getchar(),len=0;
		while(ch>='a'&&ch<='z')t[++len]=ch,ch=getchar();
		rep(i,1,len)if(s[i]!=t[i])R=i;
		per(i,len,1)if(s[i]!=t[i])L=i;
		ll ans=0;
		rep(i,1,len){
			int c=(s[i]-'a')*26+(t[i]-'a')+1;
			now=sgt1.qry(1,V,c,rt1[now]);
			if(i>=R&&dep[now]>=i-L+1){
				ans+=ed[now];
				int u=now;
				per(j,19,0)if(dep[fa[u][j]]>=i-L+1)u=fa[u][j];
				ans-=ed[fa[u][0]];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
