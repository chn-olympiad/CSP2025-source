#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;
const int N = 1.1e5+20,M = 1.1e6+20;
int n,m,k,fa[N],c[15],a[15][N];
bool vis[12];
ll sum = 1e18;
struct edge{
	int u,v,w;
	bool operator < (const edge &o) const{
		return w<o.w;
	}
}e[M],e1[M];
struct node{
	int v,w;
};
vector<node> adj[N];

bool cmp(edge x,edge y){
	return x.w<y.w;
}

void init(){
	for(int i=1;i<=n+k;i++){
		fa[i] = i;
	}
}

int find(int x){
	if(fa[x] == x)return x;
	fa[x] = find(fa[x]);
	return fa[x]; 
}

void merge(int u,int v){
	u = find(u),v = find(v);
	fa[v] = fa[u];
}

void chck(){
	init();
	int nm = m;
	for(int i = 1;i<=m;i++){
		e1[i].u = e[i].u,e1[i].v = e[i].v,e1[i].w = e[i].w;
	}
	ll sum1 = 0;
	for(int i = 1;i<=k;i++){
		if(vis[i]){
			sum1+=c[i];
			for(int j = 1;j<=n;j++){
				nm++;
				e1[nm].u = i+n,e1[nm].v = j,e1[nm].w = a[i][j];
			}
		}
	}
	sort(e1+1,e1+nm+1,cmp);
	
	for(int i = 1;i<=nm;i++){
		int u = e1[i].u,v = e1[i].v,w = e1[i].w;
		if(find(u)==find(v)) continue;
		merge(u,v);
		sum1+=w;
	}
	sum = min(sum,sum1);
}

void dfs(int i){
	if(i==n+1){
		chck();
		return;
	}
	vis[i] = 0;
	dfs(i+1);
	vis[i] = 1;
	dfs(i+1);
}

void solve(){
	cin>>n>>m>>k;
	init();
	for(int i = 1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		e[i].u = u,e[i].v = v,e[i].w = w;
		e1[i].u = u,e1[i].v = v,e1[i].w = w;
	}
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j =1 ;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(!k){
		sort(e+1,e+m+1,cmp);
		for(int i = 1;i<=m;i++){
			int u = e[i].u,v = e[i].v,w = e[i].w;
			if(find(u)==find(v)) continue;
			merge(u,v);
			sum+=w;
		}
		cout<<sum<<endl;
	}
	else{
		dfs(1);
		cout<<sum<<endl;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
