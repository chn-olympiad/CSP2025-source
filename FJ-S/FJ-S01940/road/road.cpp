#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1e6+10;
bool Mbe;

struct node{
	int u,v,w;
}edge[M*2],kedge[M]; int cnt,res;
void add(int u,int v,int w){
	edge[++cnt]={u,v,w};
}

struct DSU{
	int fa[N];
	void init(int n){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
	}
	
	int find(int x){
		if(fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		x=find(x); y=find(y);
		if(x==y) return;
		fa[x]=y;
	}
}dsu;

long long kruskal(int nod,int index){
	sort(edge+1,edge+cnt+1,[](node a,node b){
		return a.w<b.w;
	});
	long long ans=0;
	for(int i=1;i<=cnt&&nod>1;++i){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		u=dsu.find(u); v=dsu.find(v);
		if(u!=v){
			ans+=w;
			dsu.fa[u]=v;
			nod--;
			if(index){
				kedge[++res]=edge[i];
			}
		}
	}
	return ans;
}

int a[20][N],c[20];
int n,m,k;

long long solve(int cover){
	cnt=0; long long ans=0;
	int nod=n;
	for(int i=1;i<=res;i++) add(kedge[i].u,kedge[i].v,kedge[i].w);
	for(int i=0;i<k;i++){
		if(cover&(1<<i)){
			ans+=c[i];
			for(int j=1;j<=n;j++){
				add(n+i+1,j,a[i][j]);
			}
			nod++;
		}
	}
	dsu.init(n+k);
	ans+=kruskal(nod,0);
	return ans;
}

void fake_main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		add(u,v,w);
	}
	dsu.init(n);
	kruskal(n,1);
	
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	long long ans=1e15;
	for(int cover=0;cover<((1<<k)-1);cover++){
		ans=min(ans,solve(cover));
	}
	cout<<ans<<"\n";
}

bool Med;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cerr<<fabs(&Med-&Mbe)/1028576.0<<"MB\n";
	int t; t=1;
	while(t--) fake_main();
	cerr<<clock()*1.0/CLOCKS_PER_SEC*1000.0<<"ms\n";
}

