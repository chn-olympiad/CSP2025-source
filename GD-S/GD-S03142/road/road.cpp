#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gc() getchar()
#define putc(c) putchar(c)
inline int read(){
	int x=0,t=0;
	char c=gc();
	while(c<'0'||c>'9') t|=c=='-',c=gc();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
	return t?-x:x;
}
inline void write(ll x){
	if(x<0) putc('-'),x=-x;
	if(x>9) write(x/10);
	putc(x%10+'0');
}
using node=array<int,3>;
const int N=1e4+100,M=1e6+10,K=10+2,INF=2e9+10;
int n,m,k,c[K],fa[N+K],siz[N+K];
inline int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }
inline bool unnion(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return 0;
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y,siz[y]+=siz[x];
	return 1;
}
node v0[M],v1[N],v2[N*K],v3[N*K];
int t1,t2;
int main(){
//	system("fc road1.out road1.ans /n");
//	system("fc road2.out road2.ans /n");
//	system("fc road3.out road3.ans /n");
//	system("fc road4.out road4.ans /n");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		v0[i]=(node){w,u,v};
	}
	sort(v0+1,v0+m+1);
	for(int i=1;i<=n;i++)
		fa[i]=i,siz[i]=1;
	ll ans=0;
	for(int i=1;i<=m;i++){
		node tp=v0[i];
		int u=tp[1],v=tp[2];
		if(unnion(u,v)) ans+=tp[0],v1[++t1]=tp;
	}
	assert(t1==n-1);
	v1[t1+1][0]=INF;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			v2[++t2]=(node){read(),j,i+n};
	}
	sort(v2+1,v2+t2+1);
	for(int s=1;s<(1<<k);s++){
		ll res=0;
		for(int i=0;i<k;i++)
			if(s>>i&1)
				res+=c[i+1];
		if(res>=ans) continue;
		int t3=0;
		for(int i=1;i<=t2;i++){
			node tp=v2[i];
			if(s>>(tp[2]-n-1)&1)
				v3[++t3]=tp;
		}
		v3[t3+1][0]=INF;
		for(int i=1;i<=n+k;i++)
			fa[i]=i,siz[i]=1;
		int p=1,q=1;
		while(p<=t1||q<=t3){
			node tp=v1[p][0]<=v3[q][0]?v1[p++]:v3[q++];
			int u=tp[1],v=tp[2];
			if(unnion(u,v)) res+=tp[0];
		}
		ans=min(ans,res);
	}
	write(ans);
}
