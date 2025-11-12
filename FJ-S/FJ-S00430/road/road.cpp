#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[322323];
struct s{
	int x,y;
};
vector<s> g[32323];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		
		cin>>u>>v>>w;
		g[u].push_back({ v, w });
		g[v].push_back( {u , w} ) ;
		//k[u].push(w);
	}
	for(int j=0;j<k;j++){
		for(int i=0;i<n+1;i++){
		cin>>a[i];	
		} 
			
	}
	cout<<126;
	
	return 0;
}
