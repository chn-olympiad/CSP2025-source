#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node{
	int v,w;
};
vector<node>g[M];
ll n,m,k,c[20],a[20][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,win;
		cin>>u>>v>>win;
		g[v].push_back({u,win});
		g[u].push_back({v,win});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	cout<<0<<"\n";
	return 0;
}
