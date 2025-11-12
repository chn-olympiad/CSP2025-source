#include <bits/stdc++.h>
#define piii pair<int,pair<int,int>>
#define pii pair<int,int>
using namespace std;
const int N=1e4+20;
const int K=25;
const int INF=INT_MAX;
int n,m,k;
vector<int> g[N];
int G[N][N];
int fa[N];
priority_queue<piii,vector<piii>,greater<piii> > pq;
int ans1[K][N],ans2[K];
long long ans;

int find(int x){if(fa[x]==x) return x;return fa[x]=find(fa[x]);}

void merge(int u,int v){fa[find(u)]=fa[find(v)];}

void solve_tree(){
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0;
	while(pq.size()){
		auto p=pq.top();pq.pop();
		int w=p.first,u=p.second.first,v=p.second.second;
		if(find(u)!=find(v)){
			merge(u,v);
			cnt++;
			G[u][v]=G[v][u]=w;
			g[u].push_back(v);
			g[v].push_back(u);
		}
//	cout<<pq.size()<<endl;
		if(cnt==n-1) break;
	}
	return;
}

void solve(int i){
//	while(pq.size()) pq.pop();
//	for(int j=1;j<=n;j++){
//		piii t;t.first=ans1[i][j];t.second.first=i;t.second.second=j;
//		pq.push(t);
//	}
	long long sum=INF,u;
	for(int j=1;j<=n;j++){
		if(sum>ans1[i][j]){
			sum=ans1[i][j];
			u=j;
		}
	}
	for(int j=1;j<=n;j++){
		if(u==j) continue;
		if(sum+ans1[i][j]<G[u][j]){
			G[u][j]=sum+ans1[i][j];
		}
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) G[i][j]=INF;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		piii t;t.first=w;t.second.first=u;t.second.second=v;
		pq.push(t);
	}
	solve_tree();
	for(int i=1;i<=k;i++){
		cin>>ans2[i];
		for(int j=1;j<=n;j++){
			cin>>ans1[i][j];
		}
	}
	for(int i=1;i<=k;i++) solve(i);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(G[i][j]==INF) continue;
			if(find(i)!=find(j)){
				merge(i,j);
				ans+=G[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2 
1 4 6 
2 3 7
4 2 5 
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
