#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i)
#define SZ(x) ((int)x.size())

using namespace std;

typedef long long ll;

const int maxn=1e4+10,maxk=11,maxm=1e6+10;

inline int rd(){
	char ch=getchar();
	bool w=false;
	int x=0;
	while(!isdigit(ch)){
		w|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(w) x=-x;
	return x;
}

int n,m,k,a[maxk][maxn],c[maxk],id[maxn],sz[maxn+maxk],fa[maxn+maxk];

struct node{
	int u,v,w;
	bool operator < (const node &A)const{
		return w<A.w;
	}
}e[maxm],g[maxn*11],tmp[maxn*11],t2[maxk][maxn];

inline void init(){
	rep(i,1,n+k) fa[i]=i,sz[i]=1;	
}

inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);	
}

inline void merge(int u,int v){
	u=find(u); v=find(v);
	if(u==v) return;
	if(sz[u]>sz[v]) swap(u,v);
	sz[v]+=sz[u];
	fa[u]=v;	
}

inline void solve(){
	n=rd(); m=rd(); k=rd();
	rep(i,1,m){
		e[i].u=rd(); 
		e[i].v=rd();
		e[i].w=rd(); 
	}
	sort(e+1,e+1+m);
	init();
	int cur=0;
	ll res=0;
	rep(i,1,m){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v) continue;
		id[++cur]=i;
		res+=e[i].w;
		merge(u,v);
	} 
	rep(i,1,k){
		c[i]=rd();
		rep(j,1,n) a[i][j]=rd(),t2[i][j]={n+i,j,a[i][j]};
		sort(t2[i]+1,t2[i]+1+n);
	}
	rep(S,0,(1<<k)-1){
		ll t=0;
		init();
		rep(i,1,n-1) g[i]=e[id[i]];
		cur=n-1;
		rep(i,1,k){
			if((S>>(i-1))&1){
				t+=c[i];
				if(t>=res) break;
				int p1=1,p2=1,p3=0;
				while(p1<=cur && p2<=n){
					if(g[p1].w<t2[i][p2].w) tmp[++p3]=g[p1],p1++;
					else tmp[++p3]=t2[i][p2],p2++;
				}
				while(p1<=cur) tmp[++p3]=g[p1],p1++;
				while(p2<=n) tmp[++p3]=t2[i][p2],p2++;
				rep(i,1,p3) g[i]=tmp[i];
				cur=p3;
			} 
		}
		rep(i,1,cur){
			int u=find(g[i].u),v=find(g[i].v);
			if(u==v) continue;
			t+=g[i].w;
			merge(u,v);
			if(t>=res) break;
		} 
		res=min(res,t);
	}
	printf("%lld\n",res);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int _=1;
//	scanf("%d",&_);
	while(_--) solve();
}

