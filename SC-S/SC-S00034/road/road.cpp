#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;

struct NODE{
	int xv,wx;
};

vector<NODE> G[N];
int f[N][N],cnt;
bool vis[N];
void D(int s){
	memset(f,INT_MAX,sizeof(f));
	queue<int> q;
	q.push(s);
	while(q.size()){
		int p=(int)q.front();
		for(int i=0;i<(int) G[p].size();i++){
			int v=G[i].xv;int w=G[i].wx;
			f[s][v]=min(f[i][v]+w,f[s][v]);
		}	
	}
}
int main(){
	int n,m,k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back({v,w});G[v].push_back({u,w});
	}for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;i++){
			int x;cin>>x;
			G[n+i].push_back({j,x+c});G[j].push_back({n+i,x+c});
		}
	}D(1);
}