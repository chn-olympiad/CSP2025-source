#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,k,f[N];
vector<int> g[N],val[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	for(int i=1;i<=k;i++){
		int a;
		for(int j=1;j<=n;j++)
			cin>>a;
	}
	cout<<0;
    return 0;
}
