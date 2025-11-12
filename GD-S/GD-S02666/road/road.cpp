#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e6+5;
const int MAXK=10+5;
int n,m,k;
int Aflag;
long long w[MAXN],c[MAXK],a[MAXN][MAXN];
long long dis[MAXN][MAXN];
vector<int> g[MAXN];
//void bfs(int s){
//	queue<int> q;
//	q.push(s);
//	dis[s][s]=0;
//	while(!q.empty()){
//		int u=q.front();
//		for(int i=1;i<=g[u].size();i++){
//			
//		}
//	} 
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v>>w[i];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) Aflag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) Aflag=1;
		}
	}
	if(!Aflag){
		cout<<0;
	}
	return 0;
}

