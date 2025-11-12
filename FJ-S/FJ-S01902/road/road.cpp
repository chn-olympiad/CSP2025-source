#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long 
int n,m,k,ans;
struct dist{
	int son,z;
};
vector<dist> d[N];
struct node{
	int jl,bh;
	bool operator < (const node A)const{
		return jl<A.jl;
	}
};
void dij(int s,int es){
	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
		d[u].push_back({v,w});
		d[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dij(i,j);
		}		
	}
	cout<<ans;
	return 0;
}








