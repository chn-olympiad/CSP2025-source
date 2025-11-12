#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k;
struct E{
	int v,w;
};
struct EDGE{
	int u,v,w;
}e[M];
vector<E>g[N];
int fa[N];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}
int c=0;
bool cmp(EDGE x,EDGE y){
	return x.w<y.w;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		e[++c]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		int op;
		cin>>op;
		for(int j=1;j<=op;j++){
			int t;
			cin>>t;
		}
	}
	sort(e+1,e+m+1,cmp);
	init();
	int l=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			l+=e[i].w;
		}
	}
	cout<<l<<endl;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
