#include<bits/stdc++.h>
using namespace std;

const int N=10015,M=1000015;
int n,m,k,s;
vector<pair<int,int> >E[N];
vector<pair<int,pair<int,int> > >G;
vector<pair<int,pair<int,int> > >_G;
int c[20],a[20][N];
bool vis[N];

void add(int u,int v,int w){
	E[u].push_back({v,w});
	E[v].push_back({u,w});
	G.push_back({w,{u,v}});
}

void init(){
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int k=1;k<=n;k++)add(k,j,c[i]+a[i][j]);
		}
	}
}

int mtot(){
	int sum=0;
	sort(G.begin(),G.end());
	for(int i=1,j=1;j<=n-1;i++){
		int w=G[i].first;
		int u=G[i].second.first;
		int v=G[i].second.second;
		if(!vis[v]){
			j++;
			sum+=w;
			vis[v]=1;
		}
	}
	return sum;
}

void solve(){
	cout<<mtot();
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	solve();
	return 0;
}

