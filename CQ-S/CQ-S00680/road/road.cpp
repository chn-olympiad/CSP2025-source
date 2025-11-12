#include<bits/stdc++.h> 
#define int long long 
#define x first 
#define y second 
#define il inline 
#define eb emplace_back 
#define debug() puts("-----") 
using namespace std; 
typedef pair<int,int> pii; 
il int read(){ 
	int x=0,f=1; char ch=getchar(); 
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } 
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar(); 
	return x*f; 
} 
const int INF=1e18; 
const int N=1e4+5,M=1e6+10,K=12; 
int n,m,k; 
int c[K]; 
struct Node{ 
	int x,y,w1,w2,w3; 
}w[N]; 
pii f[N]; 
int ans=INF; 
int a[K][N]; 
int r[K][N]; 
int p[N],t[N]; 
il int find(int x){ 
	if(p[x]!=x) p[x]=find(p[x]); 
	return p[x]; 
} 
struct Edge{ 
	int u,v,w; 
}e[M],E[N]; 
il bool cmp(Edge a,Edge b){ 
	return a.w<b.w; 
} 
signed main(){ 
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	n=read(),m=read(),k=read(); bool flg=true; 
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read(); 
	for(int i=1;i<=k;i++){ 
		c[i]=read(); 
		for(int j=1;j<=n;j++) a[i][j]=r[i][j]=read(); 
		if(c[i]) flg=false; 
	} int lim=0; 
	if(flg) lim=(1<<k)-1; 
	for(int s=lim;s<(1<<k);s++){ 
		int res=0; 
		for(int i=1;i<=n;i++) p[i]=i; 
		for(int i=1;i<=k;i++){ 
			if(s>>(i-1)&1) res+=c[i]; 
			for(int j=1;j<=n;j++) a[i][j]=r[i][j]; 
		} while(true){ 
			int cntp=0; 
			for(int i=1;i<=n;i++) if(i==find(i)) t[++cntp]=i,w[i].x=INF,w[i].w1=0; 
			if(cntp==1) break; 
			for(int i=1;i<=m;i++){ 
				int pa=find(e[i].u),pb=find(e[i].v); 
				if(pa!=pb){ 
					if(e[i].w<w[pa].x) w[pa]={e[i].w,pb}; 
					if(e[i].w<w[pb].x) w[pb]={e[i].w,pa}; 
				} 
			} 
			for(int i=1;i<=k;i++){ 
				if(!(s>>(i-1)&1)) continue; 
				int Min=INF,id1=0,Min2=INF,id2=0; 
				for(int j=1;j<=cntp;j++) f[t[j]].x=INF; 
				for(int j=1;j<=n;j++){ 
					int wp=find(j); 
					if(a[i][j]<f[wp].x) f[wp].x=a[i][j],f[wp].y=j; 
				} for(int j=1;j<=cntp;j++){ 
					int u=t[j]; 
					if(f[u].x<=Min) Min2=Min,id2=id1,Min=f[u].x,id1=u; 
					else if(f[u].x<=Min2) Min2=f[u].x,id2=u; 
				} for(int j=1;j<=cntp;j++){ 
					int u=t[j],val,id; 
					if(id1==u) val=f[u].x+Min2,id=id2; 
					else val=f[u].x+Min,id=id1; 
					if(val<w[u].x){ 
						w[u].x=val,w[u].y=id; 
						w[u].w1=i,w[u].w2=f[u].y,w[u].w3=f[id].y; 
					} 
				} 
			} 
			for(int i=1;i<=cntp;i++) E[i]={t[i],w[t[i]].y,w[t[i]].x}; 
			sort(E+1,E+cntp+1,cmp); 
			for(int i=1;i<=cntp;i++){ 
				int pa=find(E[i].u),pb=find(E[i].v); 
				if(pa!=pb){ 
					a[w[E[i].u].w1][w[E[i].u].w2]=a[w[E[i].u].w1][w[E[i].u].w3]=0; 
					p[pa]=pb,res+=E[i].w; 
				} 
			} 
		} ans=min(ans,res); 
	} printf("%lld\n",ans); 
	return 0; 
} /*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/ 
