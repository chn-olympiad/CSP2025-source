#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)

namespace th666{
	struct input{
		#define gc getchar
		template<typename T>
		void read(T &x){
			x=0; signed f=1,ch=gc();
			while(ch<48||ch>57){
				if(ch==EOF) return;
				if(ch==45) f=-1;
				ch=gc();
			}
			while(ch>=48&&ch<=57){
				if(ch==EOF) break;
				x=(x<<3)+(x<<1)+(ch^48);
				ch=gc();
			}
			x*=f;
		}
		template<typename T>
		input& operator>>(T &x){
			read(x); return (*this);
		}
		#undef gc
	}tin;
	struct output{
		template<typename T>
		void write(T x){
			signed stk[55],top=0;
			if(x<0) x=-x,putchar(45);
			do{stk[++top]=x%10;x/=10;}while(x);
			while(top){putchar(stk[top--]|48);}
		}
		template<typename T>
		void write(T *x){
			while(*x) putchar(*(x++));
		}
		void write(const char&x){
			putchar(x);
		}
		template<typename T>
		output& operator<<(const T&x){
			write(x); return(*this);
		}
	}tout;
};
using th666::tin;
using th666::tout;

const int MAXN=1e4+5;
int n,m,kw;
int a[15][MAXN],c[15];
//bitset<MAXN> p;
//vector<pair<int,int> > G[MAXN];
struct edge{
	int u,v,w;
	bool operator<(const edge& b)const{
		return w<b.w;
	}
}; 
vector<edge> E;
//vector<edge> Ep;

//int dist[MAXN+10];
struct uset{
	int fa[MAXN],siz[MAXN];
	void init(int n){
		For(i,1,n) fa[i]=i,siz[i]=1; 
	}
	int get(int x){
		if(fa[x]==x) return x;
		return fa[x]=get(fa[x]);
	}
	bool merge(int x,int y){
		int u=get(x),v=get(y);
		if(u==v) return 0;
		if(siz[v]>siz[u]) swap(u,v);
		fa[v]=u;
		return 1;
	}
}ust;
//void prim(int st){
//	For(i,1,n+kw) dist[i]=1e9+7;
//	dist[st]=0; priority_queue<pair<int,int> > q;
//	q.push({0,st});
//	while(q){
//		pair<int,int> t=q.top();
//		q.pop();
//		for(int v:t.second){
//			
//		}
//	}
//}

void kruskal1(){
	ust.init(n);
	sort(E.begin(),E.end());
	int cnt=0,ans=0;
	for(edge& t:E){
		bool f=ust.merge(t.u,t.v);
		if(f){
			cnt++;
			ans+=t.w;
			if(cnt==n) break;
		}
	}
	tout<<ans;
}
//void kruskal2(){
//	ust.init(n);
//	sort(E.begin(),E.end());
//	int cnt=0,ans=0;
//	for(edge& t:E){
//		bool f=ust.merge(t.u,t.v);
//		if(f){
//			cnt++;
//			ans+=t.w;
//			if(cnt==n) break;
//		}
//	}
//	tout<<ans;
//}

//void check(){
//	Ep=E;
//	For(i,1,kw){
//		if(p[i]){
//			cnt+=c[i];
//			For(j,1,n)
//				Ep.push_back({j,n+i,a[i][j]}),
//				Ep.push_back({n+i,j,a[i][j]});
//		} 
//	}
//	
//}
//
//void dfs(int k){
//	if(k==kw+1){
//		check();
//		return;
//	}
//	For(i,0,1){
//		p[k]=i;
//		dfs(k+1);
//	}
//}

void solve(){
	tin>>n>>m>>kw;
	For(i,1,m){
		int u,v,w;
		tin>>u>>v>>w;
//		G[u].push_back({v,w});
//		G[v].push_back({u,w});
		E.push_back({u,v,w});
	}
	For(i,1,kw){
		tin>>c[i];
		For(j,1,n){
			tin>>a[i][j];
		}
	}
//	if(kw==0){
		kruskal1();
		return;
//	}else
//	dfs(1);
}
#define thlog5
signed main(){
	//rp=-inf
#ifdef thlog5
	#define TimuMingzi "road"
	freopen(TimuMingzi".in","r",stdin);
	freopen(TimuMingzi".out","w",stdout);
#endif
	solve();
	return 0;
}

