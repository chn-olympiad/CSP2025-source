#include<iostream>
using namespace std;
const int maxn=1e4+5;
int n,m,k;
vector<int>a[maxn];
int w[maxn][maxn],c[maxn];
bool vis[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,ww;
		scanf("%d%d%d",&u,&v,&ww);
		w[u][v]=w[v][u]=min(min(w[u][v],w[v][u]),ww);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i]);
		}
	}
	return 0;
}
