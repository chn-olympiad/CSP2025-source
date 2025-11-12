#include <bits/stdc++.h>
#define N 20001
#define int long long
using namespace std;
struct Node{
	int v,w,pre,rt;
	bool operator<(const Node &b)const{return w>b.w;}
};
struct Edge{
	int u,v,w;
	bool operator<(const Edge &b)const{return w<b.w;}
}edge[N*100];
int n,m,k,u,v,w,ans;
int dis[N],c[N],d[N],p[N],root[N];
map<int,int> mp;
bool vis[N],flag;
vector<Node> e[N];
priority_queue<Node> q;
void Prim(){
	q.push({0,0,0,0});
	while (!q.empty()){
		Node u=q.top();
		q.pop();
		if (vis[u.v])continue;
		vis[u.v]=1,ans+=u.w;
		root[u.v]=u.rt;
		if (u.v>n)d[u.v]++,p[u.v]+=u.w;
		if (u.pre>n)d[u.pre]++,p[u.pre]+=u.w;
		if (u.v<n&&u.v!=0&&u.pre<n&&u.pre!=0)flag=1;
		for (Node t:e[u.v]){
			int v=t.v;
			int w=t.w;
			cout<<"E: "<<u.v<<" "<<v<<" "<<w<<endl;
			if (vis[v]||w>=dis[v])continue;
			dis[v]=w;
			cout<<"C! \n";
			int rt=u.rt;
			if (v>n)rt=v;
			q.push({v,dis[v],u.v,rt});
		}
	}
	for (int i=1;i<=k;i++){
		if (d[n+i]<3)ans-=p[n+i];
	}
	if (!flag){
		sort(edge+1,edge+m+1);
		for (int i=1;i<=n;i++)cout<<rt[i]
		for (int i=1;i<=m;i++){
			if (root[edge[i].u]!=root[edge[i].v]){ans+=edge[i].w;break;}
		}	
	}
}
signed main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edge[i]={u,v,w};
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++){
		cin>>c[n+i];
		e[0].push_back({n+i,c[n+i]});
		for (int j=1;j<=n;j++){
			cin>>w;
			e[n+i].push_back({j,w});
		}
	}
	e[0].push_back({1,0});
	Prim();
	cout<<ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4

*/ 
