#include<bits/stdc++.h>
using namespace std;

#define int long long 
//#define double long double
#define me(x,v) memset(x,v,sizeof(x))
#define siz(x) ((int)(x).size())
#define x first
#define y second
#define L(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,r,l) for(int i=(r);i>=(l);i--) 
#define wr(...) printf(__VA_ARGS__)
#define p(x,y) pair<x,y>
#define ve(x) vector<x>

#ifdef DGR
#define dwr(...) printf(__VA_ARGS__)
#define ast(expr) assert(expr)
#else
#define dwr
#define ast
#endif

#define el "\n"

char gc(){
	return (char)getchar(); 
} 
void pc(char c){
	putchar(c);
}
int rd(){
	int sgn=0,ret=0,c=gc();
	while(c<'0'||c>'9'){
		sgn|=(c=='-');
		c=gc();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=gc();
	}
	return sgn?-ret:ret;
}

constexpr int N=1e6+7,K=20,inf=0x3f3f3f3f3f3f3f;

struct Dsu{
	int fa[N],sz[N];
	void init(int n){
		L(i,1,n){
			fa[i]=i,sz[i]=1;	
			}
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	void join(int u,int v){
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			if(sz[fu]>sz[fv]){ 
				swap(fu,fv);
			}
			fa[fu]=fv;
		}
	}
}dsu;

struct E{
	int u,v,w;
}e[N];

struct P{
	E e;
	int bel;
};

bool operator<(const P& x, const P& y){
	return x.e.w>y.e.w;
}

int n,m,k;
int c[K],a[K][N];
p(int,int) b[K][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=rd(),m=rd(),k=rd();
	L(i,1,m){
		int u=rd(),v=rd(),w=rd();
		e[i]={u,v,w};
	}
	
	sort(e+1,e+1+m,[](auto x,auto y){
		return x.w<y.w;
	});
	
	L(i,1,k){
		c[i]=rd();
		L(j,1,n){
			a[i][j]=rd();
			b[i][j]={j,a[i][j]};
		}
		sort(b[i]+1,b[i]+1+n,[&](auto x,auto y){
			return x.y<y.y;
		});
	}
	
	int cur=0;
	auto add=[&](int u,int v,int w){
//		dwr("connect (%lld,%lld,%lld)\n",u,v,w);
			cur+=w;
			dsu.join(u,v);
		
	};
	
//	dwr("start\n");
	
	priority_queue<P> pq;
	
	int ans=inf;
	L(st,0,(1<<k)-1){
//		dwr("run %lld\n",st);
		
		dsu.init(n+k);
		
		while(!pq.empty()){
			pq.pop(); 
		}
		cur=0;
		int rem=n;
		pq.push({e[1],0});
		
		static int pt[K];
		pt[0]=1;
		L(i,1,k){
			pt[i]=1;
			if((st>>(i-1))&1){
				cur+=c[i];	
				rem++;
				pq.push({{n+i,b[i][1].x,b[i][1].y},i});
			}
		}
		while(rem>1){
			P p=pq.top();
			pq.pop();
			int bel=p.bel;
			int u=p.e.u,v=p.e.v,w=p.e.w;
			pt[bel]++;
			if(bel>0){
				pq.push({{n+bel,b[bel][pt[bel]].x,b[bel][pt[bel]].y},bel});
			}else{
				pq.push({e[pt[bel]],0});
			}
		
			if(dsu.find(u)==dsu.find(v)){
				continue;
			}
			add(u,v,w);
			if(cur>=ans){
				break;
			}
			rem--;
		}
		if(cur<ans){
			ans=cur;
//			dwr("upd ans %lld\n",ans);
		}
	}
	
	wr("%lld\n",ans);
}
