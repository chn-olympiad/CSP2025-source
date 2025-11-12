#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
	int u,v;
	int w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
vector<edge> es,ans;
vector<pair<int,int> > g[20005];
int c[15];
int fa[20005];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void add(int u,int v){
	u=find(u),v=find(v);
	if (u==v)return;
	fa[v]=u;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
//	freopen("D:\\road\\road3.in","r",stdin);
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	//ÈË½ÜµØÁé 
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		es.push_back({u,v,w*2});
	}
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			int x;cin>>x;
			es.push_back({n+i,j,x*2+c[i]});
		}
	}
	for (int i=1;i<=20000;i++)fa[i]=i;
	sort(es.begin(),es.end(),cmp);
	int sm=0;
	for (edge i:es){
		if (find(i.u)!=find(i.v)){
			add(i.u,i.v);
			ans.push_back(i);
			g[i.u].push_back({i.v,i.w}),g[i.v].push_back({i.u,i.w});
			sm+=i.w;
		}
	}
	for (int i=n+1;i<=n+k;i++){
		if (g[i].size()==1){
			sm-=g[i][0].second;
		}
	}
	cout<<sm/2;
	return 0;
}
