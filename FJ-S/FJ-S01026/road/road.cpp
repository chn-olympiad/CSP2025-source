#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct edge {
	int v,w;
};
vector<vector<edge> >edge1,edge2;
vector<int> c;
void ae(vector<vector<edge> >&edges,int u,int v,int w) {
	edges[u].push_back({v,w});
	edges[v].push_back({u,w});
}
vector<int> fa;
vector<pair<int,int> > alledges;
bool cmp(pair<int,int> a1,pair<int,int>a2) {
	return edge1[a1.first][a1.second]<edge1[a2.first][a2.second];
}
int findfa(int u) {
	if(fa[u]==u)return u;
	return fa[u]=findfa(fa[u]);
}
void add(int s,int neww) {
	fa[findfa(neww)]=s;
}
int n,m,k;

//void dj(vector<vector<int> >&edges,int dis[],bool vis,int start){
//	priority_queue<qq> q;
//	while(!q.empty()){
//		auto u=q.top().u;
//		q.pop();
//		for(auto v:edges[u]){
//
//			dis[v]=min(dis[v],dis[u]+w[uv]);
//		}
//	}
//}
long long krus(int point_num) {
	cout<<"fuck\n";
	sort(alledges.begin(),alledges.end(),cmp);
	cout<<"fuck\n";
	long long total=0;
	int num=0;
	for(auto i:alledges) {
		int u,v;
		u=i.first;
		v=i.second;
		cout<<"fuck\n";
		if(fa[u]!=fa[v]) { //ºÏ²¢
		cout<<"fuck\n";cout<<edge1[u][v]<<endl;
			total+=edge1[u][v];
		
			add(u,v);
		
			num++;
		}
		
		if(point_num==num+1)break;
	}
	return total;
}
int main() {
//	freopen(,"r",stdin);
//	freopen(,"w",stdout);
	//dj
	scanf("%d%d%d",&n,&m,&k);
	edge1.resize(n+5);
	c.resize(n+5);
	fa.resize(n+5);
	for(int i=1;i<=n+5;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ae(edge1,u,v,w);
		alledges.push_back({u,v});
	}
	for(auto i:edge1){cout<<endl;for(auto j:i)cout<<j<<' ';}
//	edge2.resize(n+k+5);
//	for(int i=n+1;i<=n+k;i++){
//		scanf("%d",&c[i]);
//		for(int j=1;j<=n;j++){
//			int tmp;
//			scanf("%d",&tmp);
//			ae(edge2,i,j,tmp);
//			alledges.push_back({u,v});
//		}
//	}
	cout<<krus(n)<<endl;
	
	return 0;
}
