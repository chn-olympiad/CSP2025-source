#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct road{
	int c;
	long long w;
};
vector<road> G[10021]; 
long long ck[11];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i = 0;i<k;i++){
		cin>>ck[i];
		for(int j = 0;j<n;j++){
			int w;
			cin>>w;
			G[n+i].push_back({j,w});
			G[j].push_back({n+i,w});
		}
	}
	long long ans = -1;
	for(int i=n;i<n+k;i++){
		long long nans = 0;
		for(int j = 0;j<G[i].size();j++){
			nans += G[i][j].w;
		}
		if(ans == -1){
			ans = nans;
		}else{
			ans = min(ans,nans);
		}
	} 
	cout<<ans;
} 
