#include<bits/stdc++.h>
#define int long long
#define Xuanbo return 0
using namespace std;
const int N=2e4+10,M=2e6;
struct EDGE{
	int to,nxt,w;
}e[M<<2];
int head[N],cnt;
void add_edge(int u,int v,int d){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].w=d;
	head[u]=cnt;
}
int n,m,k;
int mxu;
int cst[N];
struct NODE{
	int pos;
	int dis;
	bool operator<(const NODE &otr)const{
		return otr.dis<dis;
	}
};
priority_queue<NODE> q;
int dis[N];
bool vis[N];
int ans;
set<int> st;
void prim(){
	while(!q.empty()){
		int u=q.top().pos;
		int d=q.top().dis;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		int numk=0;
		for(int i=1;i<=k;i++){
			if(st.find(i+n)!=st.end()){
				numk++;
			}
		}
		if(st.size()-numk==n){
			continue;
		}
		st.insert(u);
		ans+=d;
		//cout<<"u:"<<u<<" d:"<<d<<'\n';
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(!vis[v]&&dis[v]>w){
				dis[v]=w;
				q.push({v,w});
			}
		}
	}
}
bool flagA=1;
struct VIL{
	int to;
	int w;
};
vector<VIL> vil[15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,d;cin>>u>>v>>d;
		add_edge(u,v,d);
		add_edge(v,u,d);
		mxu=max({u,v,mxu});
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		if(cst[i]!=0)flagA=0;
		for(int u=1;u<=n;u++){
			int d;cin>>d;
			vil[i].push_back({u,d});
//			add_edge(mxu+i,u,d);
//			add_edge(u,mxu+i,d);
		}
	}
	if(flagA){
		for(int u=1;u<=k;u++){
			for(VIL v:vil[u]){
				add_edge(u+n,v.to,v.w);
				add_edge(v.to,u+n,v.w);
			}
		}
		memset(dis,0x3f,sizeof dis);
		dis[1]=0;
		q.push({1,0});
		prim();
		cout<<ans;
	}else{
		for(int u=1;u<=k;u++){
			for(VIL v:vil[u]){
				add_edge(u+n,v.to,v.w);
				add_edge(v.to,u+n,v.w+cst[u]);
			}
		}
		memset(dis,0x7f,sizeof dis);
		dis[1]=0;
		q.push({1,0});
		prim();
		cout<<ans;
	}
	Xuanbo;
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
