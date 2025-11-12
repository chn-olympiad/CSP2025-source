#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=12;
int n,m,k,c[K],a[K][N];
bool vis[N];
struct _{
	int u,v,w;
	bool operator<(const _& a)const{return w<a.w;}
}e[M+N*K];
int fa[N+K];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
long long sum;
void MST(){
	int cnt=0;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			cnt++;
			sum+=e[i].w;
		}
		if(cnt==n-1) break;
	}
}
void solve(){
	int cnt=0;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			if(u<=n&&!vis[u]) cnt++,vis[u]=true;
			if(v<=n&&!vis[v]) cnt++,vis[v]=true;
			fa[find(u)]=find(v);
			sum+=e[i].w;
		}
		if(cnt==n) break;
	}
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j],e[++m]=(_){i+n,j,a[i][j]};	
	}
	
	if(!k){
		MST();
		cout<<sum;
		return 0;
	}
	solve();
	return 0;
} 
