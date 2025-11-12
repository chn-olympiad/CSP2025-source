#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
using namespace std;
const int N=3e4+7;
struct node{
	long long v,w,p;
	bool operator<(const node &k)const{
		return p>k.p;
	}
	string vis;
};
struct rode{
	long long v,w;
};
bool cmp(node a,node b){
	return a.w<b.w;
}
vector<rode> g[N];
long long c[N],n,m,k,cnt=0,vis[N],ans,f[N];
int prim(){
	priority_queue<node> pq;
	string s;
	for(int i=0;i<k+n;i++){
		s+='0';
	}
	pq.push({1,0,0,s});
	vis[0]=1;
	while(pq.size()){
		node t=pq.top();
		pq.pop();
		if(vis[t.v]==1) continue;
		else ans+=t.p;
		if(t.v<=n) cnt++;
		vis[t.v]=1;
		if(cnt==n) return ans; 
		for(auto it:g[t.v]){
			if(vis[it.v]==0){
				pq.push({it.v,c[it.v]+it.w+t.w,c[it.v]+it.w,t.vis});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long i,j,u,v,w;
	cin>>n>>m>>k;
	g[0].push_back({1,0});
	g[1].push_back({0,0});
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(i=1;i<=k;i++){
		cin>>c[i+n];
		for(j=1;j<=n;j++){
			scanf("%d",&w);
			g[i+n].push_back({j,w});
			g[j].push_back({i+n,w});
		}
	}
	cout<<prim();
	return 0;
}
