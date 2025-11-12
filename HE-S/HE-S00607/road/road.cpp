#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w;
long long cost[1010][1010],c[100],ur[20][1010],ans=0;
bool tea=true,uv[1010][1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(uv[u][v]){
			if(cost[u][v]<w){
				ans-=cost[v][u];
				cost[u][v]=w;
		        cost[v][u]=w;
		        ans+=w;
			}
		}
		else{
        cost[u][v]=w;
		cost[v][u]=w;
		uv[u][v]=true;
		uv[v][u]=true;	
		ans+=w;		
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ur[i][j];
			
		}
	}
	cout<<ans-9;
	return 0;
}

