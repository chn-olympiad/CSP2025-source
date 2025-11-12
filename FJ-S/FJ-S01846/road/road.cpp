#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int n,m,k;
int dist[10005];
bool vis[10005]={0};
int vili[10][10005];
long long sum;
void stre(int pos){
	dist[pos]=0;
	for(int i=1;i<=n;i++){
		int cur=-1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&cur==-1)cur=j;
			else if(!vis[j]&&dist[j]<dist[cur])cur=j;
		}
		vis[cur]=true;
		sum+=dist[cur];
		for(int j=1;j<=n;j++){
			if(!vis[j])
			dist[j]=min(dist[j],a[cur][j]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,'0xFFFFFFF',sizeof(a));
	memset(dist,'0xFFFFFFF',sizeof(dist));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>vili[i][j];
		}
	}
	stre(1);
	cout<<sum;
	return 0;
} 
