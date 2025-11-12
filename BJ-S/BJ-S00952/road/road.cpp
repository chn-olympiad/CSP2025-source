#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define REPG(i,g,x) for(int i=g.head[x];~i;i=g.edge[i].nxt)
#define LL long long

template<class T>
inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
template<class T>
inline void write(T x){
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}

const int N=1e4+50,M=2e6+5,KF=12;
int n,m,k;
int a[KF][N],c[KF];
vector<array<int,2> > b[KF];
struct dsu{
	int fa[N];
	inline int getfa(int x){
		return fa[x]==x?x:fa[x]=getfa(fa[x]);
	}
	inline bool merge(int x,int y){
		int fx=getfa(x),fy=getfa(y);
		if(fx==fy) return 0;
		return fa[fx]=fy,1;
	}
	inline void init(int n){
		rep(i,1,n) fa[i]=i;
	}
};

dsu kru;
struct edge{
	int u,v,w;
	inline bool operator<(const edge &b)const{
		return w<b.w;
	}
};
edge pe[M],tr[N];
void PreKruscal(){
	sort(pe+1,pe+m+1);
	kru.init(n);
	int cnt=0;
	rep(i,1,m){
		int u=pe[i].u,v=pe[i].v;
		if(kru.merge(u,v)) {
			cnt++;tr[cnt]=pe[i];
		}
		if(cnt==n-1) break;
	}
}
namespace sub1{
	edge e[N*KF];
	dsu d;
	LL calc(int s){
		rep(i,1,n-1) e[i]=tr[i];
		int cnte=n-1,cntp=n;LL res=0;
		rep(j,1,k){
			if((s>>(j-1))&1){
				res+=c[j];cntp++;
				rep(i,1,n) e[++cnte]={i,n+j,a[j][i]};
			} 
		}
		sort(e+1,e+cnte+1);d.init(n+k);
		int cnt=0;
		rep(i,1,cnte){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(d.merge(u,v)){
				cnt++;
				res+=w;
			}
			if(cnt==cntp-1) break;
		}
		return res;
	}
	void work(){
		int U=(1<<k)-1;
		LL ans=1e18;
		rep(s,0,U) ans=min(ans,calc(s));
		printf("%lld\n",ans);
	}

}

namespace sub2{
	edge e[N*KF],g[N*KF];
	dsu d;
	LL calc(int s){
		rep(i,1,n-1) e[i]=tr[i];
		int cnte=n-1,cntp=n;LL res=0;
		int pc=__builtin_popcount(s);
		if(pc>1){
			rep(j,1,k){
				if((s>>(j-1))&1){
					res+=c[j];cntp++;
					int hd1=1,hd2=0,tl=0;
					while(hd1<=cnte || hd2<n){
						if(hd1>cnte) g[++tl]={b[j][hd2][1],n+j,b[j][hd2][0]},hd2++;
						else if(hd2>n) g[++tl]=e[hd1],hd1++;
						else if(e[hd1].w<b[j][hd2][0]) g[++tl]=e[hd1],hd1++;
						else g[++tl]={b[j][hd2][1],n+j,b[j][hd2][0]},hd2++;
					}
					// rep(i,1,tl) printf("%d %d %d\n",g[i].u,g[i].v,g[i].w);
					// printf("---------\n");
					swap(e,g);cnte=tl;
				} 
			}
		}else{
			rep(j,1,k){
				if((s>>(j-1))&1){
					res+=c[j];cntp++;
					rep(i,1,n) e[++cnte]={i,n+j,a[j][i]};
				} 
			}
			sort(e+1,e+cnte+1);
		}
		
		// sort(e+1,e+cnte+1);
		d.init(n+k);
		int cnt=0;
		rep(i,1,cnte){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(d.merge(u,v)){
				cnt++;
				res+=w;
			}
			if(cnt==cntp-1) break;
		}
		return res;
	}
	void work(){
		int U=(1<<k)-1;
		LL ans=1e18;
		rep(s,0,U) ans=min(ans,calc(s));
		printf("%lld\n",ans);
	}

}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	rep(i,1,m) read(pe[i].u),read(pe[i].v),read(pe[i].w);
	rep(j,1,k) {
		read(c[j]);
		rep(i,1,n) read(a[j][i]),b[j].push_back({a[j][i],i});
		sort(b[j].begin(),b[j].end());
	}
	// cerr<<"1***"<<endl;
	PreKruscal();
	// cerr<<"2***"<<endl;
	if(n<=1000 || k<=5) sub1::work();
	else sub2::work();
	// sub1::work();
	return 0;
}