#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct a{
	int u;
	int v;
	int w;
}road[100005];
int city[110000][10004]; //city[k][k]是改造价格 
int main(){
//	freopen("road.in","w",stdin);
//	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}for(int i=0;i<k;i++){
		cin>>city[i][i];
		for(int j=1;j<=n&&j!=i;j++) cin>>city[i][j];
	}
	for(int i=0;i<m;i++){
			if(road[i].w>city[road[i].v][road[i].u]+city[road[i].v][road[i].v]||road[i].w>city[road[i].u][road[i].v]+city[road[i].u][road[i].u]){
				if(city[road[i].v][road[i].u]+city[road[i].v][0]>city[road[i].u][road[i].v]+city[road[i].u][0]){
					ans+=city[road[i].u][road[i].v];
					ans+=city[road[i].u][road[i].u];
				}else
				ans+=city[road[i].v][road[i].u];
				ans+=city[road[i].v][road[i].v];
			}else
			ans+=road[i].w;
	}cout<<ans;
	return 0;
}
