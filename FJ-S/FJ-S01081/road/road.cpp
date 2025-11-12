#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
struct edge{
	int u,v,w;
};
struct dsu{
	int n;
	dsu(int n):n(n){
		fa.resize(n+2); 
		siz.resize(n+2);
		init();
	}
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			siz[i]=1;
		}
	}
	vector<int> fa,siz;
	int find(int x){
		if(x!=fa[x]) fa[x]=find(fa[x]);
		return fa[x];
	}
	bool merge(int x,int y){
		int tx=find(x),ty=find(y);
		if(tx==ty){
			return false;
		}
		if(siz[tx]>siz[ty]){
			swap(tx,ty);
		}
		fa[tx]=ty;
		siz[ty]+=siz[tx];
		return true;
	}
};
struct solution{
	int n,m,k;
	vector<edge> e;
	vector<int> c;
	vector<vector<int>> a;
	solution(int n,int m,int k,vector<edge> e,vector<int> c,vector<vector<int>> a):n(n),m(m),k(k),e(e),c(c),a(a),d(n+k){
		E.resize(n*k+n+2);
		flag.resize(k+2);
	}
	vector<edge> E;
	vector<int> flag; 
	int tot;
	dsu d;
	ll solve(int S){
		ll ans=0;
		int now=0;
		for(int i=1;i<=k;i++){
			if((S>>i-1)&1){
				ans+=c[i];
				flag[i]=1;
				now++;
			}
			else{
				flag[i]=0;
			}
		}
		d.init(); 
		int cnt=0;
		for(int i=1;i<=tot;i++){
			if(E[i].u>n&&!flag[E[i].u-n]){
				continue;
			}
			if(E[i].v>n&&!flag[E[i].v-n]){
				continue;
			}
			if(d.merge(E[i].u,E[i].v)){
				cnt++;
				ans+=E[i].w;
			}
			if(cnt==n+now-1){
				return ans;
			}
		}
		return ans;
	}
	ll main(){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				E[(i-1)*n+j]={n+i,j,a[i][j]};
			}
		}
		sort(e.begin()+1,e.begin()+m+1,[](edge x,edge y){
			return x.w<y.w; 
		});
		d.init();
		tot=n*k;
		for(int i=1;i<=m;i++){
			if(d.merge(e[i].u,e[i].v)){
				E[++tot]=e[i];
			}
		}
		sort(E.begin()+1,E.begin()+tot+1,[](edge x,edge y){
			return x.w<y.w;
		});
		ll ans=INF;
		for(int i=0;i<(1<<k);i++){
			ans=min(ans,solve(i));
		}
		return ans;
	}
};
struct IO{
	int n,m,k;
	vector<edge> e;
	vector<int> c;
	vector<vector<int>> a;
	IO(){
		cin>>n>>m>>k;
		e.resize(m+2);
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		c.resize(k+2);
		a.resize(k+2,vector<int>(n+2));
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j]; 
			}	
		}
	}
	ll ans;
	~IO(){
		cout<<ans<<"\n";
	}
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	IO io;
	solution sol(io.n,io.m,io.k,io.e,io.c,io.a);
	io.ans=sol.main();
	return 0;
} 
