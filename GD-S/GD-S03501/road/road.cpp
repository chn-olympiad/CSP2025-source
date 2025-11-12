#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll MAXN=2e5+5;
int n,m,k;
struct Edge{
	ll u,v,w;
	bool friend operator < (Edge x,Edge y){
		return x.w<y.w;
	}
}edge[MAXN];
int fa[MAXN];
void init(){for(int i=1;i<=n;i++){fa[i]=i;}}
int get(int x){
	if(fa[x]==x){return x;}
	else return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	int fx=fa[x];
	int fy=fa[y];
	if(fx!=fy){fa[fx]=fy;}
}
bool same(int x,int y){
	if(get(x)==get(y)){return 1;}
	else return 0;
}
ll c[MAXN];//修复村庄 1e4+j所要的花费 
int vis[MAXN];//村庄是否已经改造过 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	init();	
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int s=1;s<=k;s++){
		int j=n+s;//村庄的编号 
		cin>>c[j];
		for(int i=1;i<=n;i++){
			edge[++m].u=j; 
			edge[m].v=i;
			cin>>edge[m].w;
		}
	}
	sort(edge+1,edge+m+1);
	int e=0;//取的边数
	int ans=0; 
	for(int i=1;i<=m;i++){
		if(same(edge[i].u,edge[i].v)){continue;}
		merge(edge[i].u,edge[i].v);
		e++;
		ans+=edge[i].w;
	} 
	cout<<ans;
	
	return 0;
} 

