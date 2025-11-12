#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k,road[10007][10007],town[17][10007],x[10007],ans=0;
int u,v,w;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		road[u][v]=w;
		road[v][u]=w;
		x[i]=w;
	}for(int i=1;i<=k;i++){
		cin>>town[i][0];
		for(int j=1;j<=n;j++){
			cin>>town[i][j];
		}
	}
	sort(x+1,x+m+1);
	for(int i=1;i<=n-1;i++){
		ans+=x[i];
	}
	cout<<ans;
	
	return 0;
}
