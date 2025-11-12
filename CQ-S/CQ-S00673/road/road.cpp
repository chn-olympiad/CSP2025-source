#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int C=1e4+15,K=15;
struct node{
	int u,v;
	ll w;
	friend bool operator>(node a,node b){return a.w>b.w;}
};
int n,m,k,fa[C];
ll a,ans=LLONG_MAX,c[K];
bool cho[K];
vector<node> V[K];
priority_queue<node,vector<node>,greater<node>> G,E;
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	if(u!=fa[u]) merge(fa[u],v);
	fa[u]=v;
	return ;
}
void dfs(int step){
	if(step>k){
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int rem=n;
		ll cost=0;
		E=G;
		for(int i=1;i<=k;i++){
			if(cho[i]){
				rem++;
				cost+=c[i];
				for(auto p:V[i]) E.push(p);
			}
		}
		while(!E.empty()){
			if(rem==1) break;
			auto now=E.top();
			E.pop();
			int x=find(now.u),y=find(now.v);
			if(x!=y){
				rem--;
				merge(x,y);
				cost+=now.w;
			}
		}
		ans=min(ans,cost);
		return ;
	}
	cho[step]=false;
	dfs(step+1);
	cho[step]=true;
	dfs(step+1);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		G.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a);
			V[i].push_back({j,n+i,a});
		}
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
