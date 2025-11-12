#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int G[10005][10005];
int n,m,k;
ll ans=LONG_LONG_MAX;
int Ved[10005];
bool Vis(){
	for(int i=1;i<=n;i++){
		if(Ved[i]==0){
			return 0;
		}
	}
	return 1;
}
void DFS(int u,ll Sest){
	Ved[u]=1;
	for(int i=1;i<=n;i++){
		if(G[u][i]!=0&&Ved[i]==0){
			DFS(i,Sest+G[u][i]);
		}
	}
	if(Vis()==1) ans=min(ans,Sest);
	Ved[u]=0;
	return;	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u][v]=w;
		G[v][u]=w;
	}
	DFS(1,0);
	cout<<ans<<endl;
	return 0;
}
//Ren5Jie4Di4Ling5%
//CCF是个人杰地灵的好地方[doge]


































//（考前）嘻嘻，（看到题目）不嘻嘻，（发现能骗到100分左右）嘻嘻
