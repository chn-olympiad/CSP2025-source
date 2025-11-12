#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define eb emplace_back
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<21],*p3=obuf;
inline char gc(){return p1==p2?(p2=(p1=buf)+fread(buf,1,1<<21,stdin),(p1==p2?EOF:*p1++)):(*p1++);}
inline int read(){
	int res=0;
	char c=gc();
	while(c<'0'||c>'9') c=gc();
	while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=gc();
	return res;
}
inline void pc(char c){
	p3-obuf<=1<<20?(*p3++=c):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=c);
}
inline void write(ll x){
	if(x>9) write(x/10);
	pc(x%10^48);
}
const int N=2e5+10,M=5e6+10,B=450;
int n,m,q,go[M][26],fa[M],tot,a[N],b[N],h[M],ne[M],e[M],idx,in[M],out[M],tim;
ll ans[N];
char S[M],T[M];
inline void add(int u,int v){
//	cout<<u<<" -> "<<v<<"\n";
	ne[++idx]=h[u],h[u]=idx,e[idx]=v;
}
inline int ins(char ch[],int len){
	int p=0;
	for(int i=0;i<len;++i){
		int t=ch[i]-'a';
		if(!go[p][t]) go[p][t]=++tot;
//		cout<<p<<" - "<<go[p][t]<<" "<<t<<" edge\n";
		p=go[p][t];
	}
	return p;
}
inline void dfs(int u){
	in[u]=++tim;
	for(int i=h[u];i;i=ne[i]) dfs(e[i]);
	out[u]=tim;
}
inline void build(){
	static int q[M];
	int hh,tt;
	q[hh=tt=1]=0;
	while(hh<=tt){
		int u=q[hh++];
//		cout<<u<<" "<<fa[u]<<"--\n";
		for(int i=0;i<26;++i){
			int v=go[u][i];
			if(v){
				q[++tt]=v;
				fa[v]=u?go[fa[u]][i]:0;
			}
			else{
				go[u][i]=go[fa[u]][i];
			}
		}
	}
	for(int i=1;i<=tot;++i) add(fa[i],i);
	dfs(0);
}
struct node{
	int l,r,id,k;
};
vector<node>G[M],ask[M];
int val[N<<1],be[N<<1],laz[N<<1],ls[N<<1],rk[M];
inline void mdf(int l,int r,int x){
	l=rk[l],r=rk[r];
	int il=be[l],ir=be[r];
	if(il==ir){
		for(int i=l;i<=r;++i) val[i]+=x;
		return ;
	}
	int R=(il+1)*B-1,L=ir*B;
	for(int i=l;i<=R;++i) val[i]+=x;
	for(int i=L;i<=r;++i) val[i]+=x;
	for(int i=il+1;i<ir;++i) laz[i]+=x;
}
inline int query(int x){
	x=rk[x];
	return val[x]+laz[be[x]];
}
int main(){
//	freopen("data.txt","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	int sl=0;
	for(int i=1;i<=n;++i){
		int len=0;
		char c=gc();
		while(c<'a'||c>'z') c=gc();
		while(c>='a'&&c<='z') S[len++]=c,c=gc();
		a[i]=ins(S,len);
		len=0;c=gc();
		while(c<'a'||c>'z') c=gc();
		while(c>='a'&&c<='z') S[len++]=c,c=gc();
		b[i]=ins(S,len);
		sl+=len;
	}
	build();
	int tn=0;
	for(int i=1;i<=n;++i) ls[++tn]=in[b[i]]-1,ls[++tn]=out[b[i]];
	sort(ls+1,ls+1+tn);
	tn=unique(ls+1,ls+1+tn)-ls-1;
	for(int i=1,j=0;i<=tim;++i) rk[i]=j,j+=(j<tn&&i==ls[j+1]);
	for(int i=1;i<=tn;++i) be[i]=i/B;
	for(int i=1;i<=q;++i){
		int len=0;
		char c=gc();
		while(c<'a'||c>'z'){
			c=gc();
		}
		while(c>='a'&&c<='z'){
			S[++len]=c;
			c=gc();
		}
		int len2=0;c=gc();
		while(c<'a'||c>'z') c=gc();
		while(c>='a'&&c<='z') T[++len2]=c,c=gc();
		if(len!=len2) continue;
		int pl=1,pr=len;
		while(pl<=n&&S[pl]==T[pl]) ++pl;
		while(pr&&S[pr]==T[pr]) --pr;
		for(int j=1,u=0,v=0;j<=len;++j){
			u=go[u][S[j]-'a'],v=go[v][T[j]-'a'];
			if(j>=pr) ask[in[u]].eb((node){in[v],0,i,1});
		}
		for(int j=pl+1,u=0,v=0;j<=len;++j){
			u=go[u][S[j]-'a'],v=go[v][T[j]-'a'];
			if(j>=pr) ask[in[u]].eb((node){in[v],0,i,-1});
		}
	}
	for(int i=1;i<=n;++i){
		G[in[a[i]]].eb(node{in[b[i]],out[b[i]],i,1});
		G[out[a[i]]+1].eb(node{in[b[i]],out[b[i]],i,-1});
	}
	for(int i=1;i<=tim;++i){
		for(node j:G[i]) mdf(j.l,j.r,j.k);
		for(node j:ask[i]) ans[j.id]+=j.k*query(j.l);
	}
	for(int i=1;i<=q;++i) write(ans[i]),pc('\n');
	return fwrite(obuf,p3-obuf,1,stdout),0;
}
