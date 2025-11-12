#include<bits/stdc++.h>
#define sf scanf 
#define pf printf  
#define rep(x,y,z) for(int x=y;x<=z;x++) 
#define per(x,y,z) for(int x=y;x>=z;x--) 
using namespace std;
typedef long long ll;
namespace wing_heart {
	#define isdigit(x) (x>='0' && x<='9') 
	#define gc getchar_unlocked
	void read(int &x) {
		x=0;
		char ch=gc();
		while(!isdigit(ch)) ch=gc();
		while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch-'0'), ch=gc();
	}
	constexpr int N=1e4+7,M=1e6+7,K=10,infint=0x3f3f3f3f;
	constexpr ll infll = 0x3f3f3f3f3f3f3f3f;
	ll ans,sum;
	int n,m,k;
	struct edge {
		int u,v,w;
		bool operator < (edge b) const { return w < b.w; }
		bool operator > (edge b) const { return w > b.w; }
	};
	edge e0[M],_e0[N];
	int fa[N+K];
	int findfa(int x) { return fa[x] ? fa[x]=findfa(fa[x]) : x; }
	bool merge(int u,int v) {
		u=findfa(u), v=findfa(v);
		if(u==v) return 0;
		fa[v]=u;
		return 1;
	}
	struct pii {
		int v,w;
		bool operator < (pii b) const { return w < b.w; }
	};
	pii e1[K][N];
	int c[K];
	int it[K];
	void main() {
		read(n), read(m), read(k);
		rep(i,1,m) {
			int u,v,w;
			read(u), read(v), read(w);
			e0[i] = {u,v,w};
		}
		sort(e0+1,e0+m+1);
		int cnt=0;
		rep(i,1,m) {
			if(merge(e0[i].u,e0[i].v)) {
				ans+=e0[i].w;
				_e0[++cnt] = e0[i];
			}
		}
		// assert(cnt==n-1);
		rep(i,0,k-1) {
			read(c[i]);
			int w;
			rep(j,1,n) read(w), e1[i][j] = {j,w};
			sort(e1[i]+1,e1[i]+n+1);
		}
		rep(i,1,(1<<k)-1) {
			memset(fa,0,sizeof(fa));
			vector<int> vec;
			sum=0;
			rep(j,0,k-1) if((i>>j)&1) vec.push_back(j), sum+=c[j], it[j]=1;
			priority_queue<edge,vector<edge>,greater<edge> > q;
			for(int x : vec) q.push({x,e1[x][it[x]].v,e1[x][it[x]].w}), ++it[x];
			rep(j,1,n-1) {
				while(q.size() && q.top().w < _e0[j].w) {
					if(merge(q.top().u+n+1,q.top().v)) sum+=q.top().w;
					int x = q.top().u;
					q.pop();
					if(it[x]<=n) q.push({x,e1[x][it[x]].v,e1[x][it[x]].w}), ++it[x];
				}
				if(merge(_e0[j].u,_e0[j].v)) sum+=_e0[j].w;
			}
			// pf("sum = %lld\n",sum);
			ans=min(ans,sum);
		}
		pf("%lld\n",ans);
	}
} 
int main() {
	#ifdef LOCAL 
	// freopen("in.txt","r",stdin);
	freopen("my.out","w",stdout);
	#else 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif 
	wing_heart :: main();
}