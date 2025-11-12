#include<bits/stdc++.h>
using namespace std;
int graph[10010][10010],town[10010];
bool vis[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,now=0,c,a;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>u>>v>>w;
		graph[u][v]=w;
		graph[v][u]=w;
	}
	int minc=214748364;
	for(int i=0;i<k;i++){
		cin>>c;
		minc=min(minc,c);
		for(int j=0;j<n;j++){
			cin>>a;
			graph[c][j]=a;
			graph[j][c]=a;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int min=214748364,minindex;
		for(int j=0;j<n;j++){
			if(graph[now][j]<min&&!vis[j]){
				min=graph[now][j];
				minindex=j;
				vis[j]=true;
			}
		}
		ans+=min;
		now=minindex;
	}
	cout<<ans+minc<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
