#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int n,m,k,g[N][N],f[N];

int getfather(int x){
	if(f[x]==x) return x;
	else f[x]=getfather(x);
}

void kruscal(){
	if(getfather(x)!=getfather(y))
	ans+=g[x][y];
	f[y]=f[x];
	cout<<;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	kruscal();
	return 0;
}
