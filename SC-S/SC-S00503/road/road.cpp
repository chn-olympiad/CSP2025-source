#include<bits/stdc++.h>
using namespace std;
#define AK ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqrt sqrtl
#define int long long
struct edge{
	int u,v,w;
	friend bool operator<(edge aa,edge bb){
		return aa.w<bb.w;
	}
};
const int maxn=10006;
int c[maxn],dis[maxn];
bool vis[maxn];
vector<edge> G;
int fa[maxn];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[fa[x]]=fa[y];
}
void reset(){
	for(int i=1;i<=maxn;i++)fa[i]=i;
}
int mst(){
	int ans=0;
	reset();
	sort(G.begin(),G.end());
	for(edge i:G){
		int u=i.u,v=i.v,w=i.w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	//大概就是一个MST，花费一定的价格多开一个点
	//跑k次MST
	//
	AK;
	int n,m,k;
	bool tsA=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G.push_back({u,v,w});
		G.push_back({v,u,w});
	}
	cerr<<"ok";
	int tans=mst();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)tsA=0;
		for(int j=1;j<=n;j++){
			int aij;
			cin>>aij;
			G.push_back({i+n,j,aij});
			G.push_back({j,i+n,aij});
			if(aij!=0)tsA=0;
		}
		tans=min(tans,mst()+c[i]);
	}
	if(tsA){
		cout<<0;
		return 0;
	}
	cout<<tans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/