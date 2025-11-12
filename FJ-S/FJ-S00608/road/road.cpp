#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace qwq{
	struct Edge{
		int u,v,w;
		Edge(){}
		Edge(int u_,int v_,int w_):u(u_),v(v_),w(w_){}
	};
	const int N=1e4+114,K=15,Inf=0x3f3f3f3f3f3f3f3f;
	int n,m,k,c[K],a[K][N],ans;
	vector<Edge> bian;
	vector<Edge> E[K],E_,xz[K];
	int fa[N];
	void mer(vector<Edge>& a,vector<Edge>& b,vector<Edge>& c){
		c.resize(a.size()+b.size());
		for(int i=0,j=0,k=0;i<(int)a.size() || j<(int)b.size();){
			if((i<(int)a.size()?a[i].w:Inf)<(j<(int)b.size()?b[j].w:Inf)){
				c[k++]=a[i++];
			}
			else{
				c[k++]=b[j++];
			}
		}
	}
	int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
	bool mer(int u,int v){
		u=getfa(u),v=getfa(v);
		if(u!=v){
			fa[v]=u;
			return 1;
		}
		return 0;
	}
	void work(vector<Edge>& E1,vector<Edge>& E2,int n){
		for(int i=1;i<=n;++i) fa[i]=i;
		E2.clear();
		for(Edge& e:E1){
			if(mer(e.u,e.v)){
				E2.push_back(e);
			}
		}
	}
	void dfs(int dep,int l,int sc){
		{
			int tmp=sc;
			for(Edge& e:E[dep]) tmp+=e.w;
			ans=min(ans,tmp);
//			cout << tmp << endl;
		}
		for(int i=l;i<=k;++i){
			mer(E[dep],xz[i],E_);
			work(E_,E[dep+1],n+k);
			dfs(dep+1,i+1,sc+c[i]);
		}
	}
	signed mian(){
		cin >> n >> m >> k;
		while(m--){
			int u,v,w;
			cin >> u >> v >> w;
			bian.push_back(Edge(u,v,w));
		}
		for(int i=1;i<=k;++i){
			cin >> c[i];
			for(int j=1;j<=n;++j){
				cin >> a[i][j];
				xz[i].push_back(Edge(n+i,j,a[i][j]));
			}
		}
		sort(bian.begin(),bian.end(),[](Edge x,Edge y)->bool{return x.w<y.w;});
		work(bian,E[0],n+k);
		for(int i=1;i<=k;++i){
			sort(xz[i].begin(),xz[i].end(),[](Edge x,Edge y)->bool{return x.w<y.w;});
		}
		ans=Inf;
		dfs(0,1,0);
		cout << ans << endl;
//		cout << clock() << endl;
		return 0;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	qwq::mian();
	return 0;
}
