#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,minn=LLONG_MAX;
struct Edge{
	int u,v,w;
	bool operator<(const Edge& other)const{
		return w<other.w;
	}
};
int can[20];
bitset<20> vis;
vector<Edge> g;
vector<Edge> c;
int buildcity[20];
class Node{
	int fa[1010];
public:
    Node(){for(int i=1;i<=1000;i++)fa[i]=i;}
    int find(int x){
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	bool insame(int x,int y){
		x=find(x);y=find(y);
		return x==y;
	}
	void merge(int x,int y){
		x=find(x);y=find(y);
		fa[x]=y;
	}
};
int kru(){
	Node a;
	vector<Edge> mp;
	mp=g;
	//cout<<can[0];
	for(int j=1;j<=can[0];j++){
		int u=can[j];
		//cout<<u<<endl;
		for(int i=1;i<c.size();i++){
			//cout<<c[i].u<<" "<<c[i].v<<" "<<c[i].w<<endl;
			if(c[i].u==u||c[i].v==u){
				mp.push_back(c[i]);
			}
		}
	}
	//for(auto e:mp)cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";
	sort(mp.begin(),mp.end());
	//for(auto x:mp)cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
	int ans=0,cnt=0;
	for(auto edge:mp){
		int u=edge.u,v=edge.v,w=edge.w;
		if(a.insame(u,v))continue;
		cnt++;
		ans+=w;
		a.merge(u,v);
		//cout<<u<<" "<<v<<" "<<w<<"\n";
		if(cnt==n-1)break;
	}
	return ans;
}
/*
void dfs(int p,int last){
	if(p>last){
		can[0]=0;
		int build=0;
		for(int i=1;i<=last;i++){
			if(vis[i]){
				build+=buildcity[i];
				can[++can[0]]=i;
			}
		}
		minn=min(minn,kru()+build);
		return ;
	}
	vis[p]=1;
	dfs(p+1,last);
	vis[p]=0;
	dfs(p+1,last);
	return ;
}
*/
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(int j=1;j<=k;j++){
		cin>>buildcity[j];
		for(int i=1;i<=n;i++){
			int w;
			cin>>w;
			c.push_back({i,j,w});
		}
	}
	cout<<kru();
    return 0;
}
