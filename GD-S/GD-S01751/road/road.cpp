#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define sf scanf
#define pf printf
struct eath{
	ll v,w;
};
struct note{
	ll u,ans;
};
vector<eath> a[10030];
int n,m,k,oneto[10030];
ll vis[10030];
ll lastu=1e17;
queue<note> q;
void DFS(int u,int last,ll ans){
	bool f=1;
	//cerr<<u<<endl;
	for(int i=1;i<=n;i++){
		if(vis[i]==1e17)f=0;
	}
	if(f==1){
		lastu=min(lastu,ans);
		//if(ans==8)cerr<<u<<endl;
		return ;
	}
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i].v;
		ll w=a[u][i].w;
		if(v!=last&&vis[v]>w+oneto[v]+ans){
			vis[v]=w+oneto[v]+ans,ans+=w+oneto[v],DFS(v,u,ans);
		}
	}
	return ;
}
int main(){
	fin("road.in");
	fout("road.out");
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		ll w;
		sf("%lld",&w);
		oneto[n+i]=w;
		for(int j=1;j<=n;j++){
			sf("%lld",&w);
			a[n+i].push_back({j,w});
			a[j].push_back({n+i,w});
		}
	}
	for(int i=1;i<=n+k;i++){
		vis[i]=1e17;
	}
	vis[1]=0;
	//½¨Í¼
	DFS(1,0,0);
	cout<<lastu;
	return 0;
}
