#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=20;

struct edge{
	int u,v,w;
	bool operator<(edge it){
		return w<it.w;
	}
}; 

int n,m,k;
edge e[M];
int f[N];
vector<pair<int,int>>g[N];
int c[K],a[K][N];

void init(){
	for(int i=0;i<N;i++){
		f[i]=i;
	}
}

int find(int u){
	return u==f[u]?u:(f[u]=find(f[u]));
}

void merge(int u,int v){
	u=find(u),v=find(v);
	f[v]=u;
}

void kruskal(){
	init();
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1);
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v)){
			continue;
		}
		merge(u,v);
		cnt++;
		sum+=e[i].w;
		if(cnt==n-1){
			break;
		}
	}
	cout<<sum;
}

bool check(){
	for(int j=1;j<=k;j++){
		if(c[j]){
			return false;
		}
	}
	return true;
}

void c0(){
	for(int j=1;j<=k;j++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(u!=v){
					e[++m]={u,v,a[j][u]+a[j][v]};
					g[e[m].u].push_back({e[m].v,e[m].w});
					g[e[m].v].push_back({e[m].u,e[m].w});
				}
			}
		}
	}
	init();
	sort(e+1,e+m+1);
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v)){
			continue;
		}
		merge(u,v);
		cnt++;
		sum+=e[i].w;
		if(cnt==n-1){
			break;
		}
	}
	cout<<sum;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef local
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	#endif
	cin>>n>>m>>k;
	if(k==0){
		kruskal();
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		g[e[i].u].push_back({e[i].v,e[i].w});
		g[e[i].v].push_back({e[i].u,e[i].w});
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	if(n*n*k<=3e8&&check()){
		c0();
		return 0;
	}
	return 0;
}
