#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1; 
int n,m,k,c[N],ans=INT_MAX,v[N];
struct P{
	int a,b;
}; 
vector<P> g[N];
void S(int x,int sum){
  	int f=0;
	for(int i=1;i<=m;i++){
		if(v[i]) f=1;
		else{
			f=0;
			break;
		}
	}
	if(f){
		ans=min(sum,ans);
		return;
	}
	for(auto it:g[x]){
		v[x]=1;
		S(it.a,it.b+sum);
		v[x]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			int u;
			cin>>u;
			g[i].push_back({i*1000,u});
			g[i*1000].push_back({i,u});
		}
	}
	cout<<ans;
	return 0;
}
