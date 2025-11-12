#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<long long, long long>
#define db double;
#define endl "\n"

struct edge{
	int u,v,w;
	
	bool operator<(edge oth){
		return w < oth.w;
	}
};

const int MXN = 1e4+10, MXM = 2e6+10;
int n,m,k;
edge edges[MXM];
int a[15][MXN], c[15], fa[MXN];

int getfa(int x){
	return (fa[x] == x)? fa[x]: fa[x] = getfa(fa[x]);
}

void merge(int x, int y){
	int u = getfa(x);
	int v = getfa(y);
	fa[u] = v;
}

int kruskal(){
	sort(edges+1,edges+m+k*n+1);
	
	int res = 0;
	for(int i = 1; i <= m+k*n; i++){
		edge cur = edges[i];
		//cout << cur.u << "(" << fa[cur.u] << ") - " << cur.v << "("<< fa[cur.v] << ") w="<< cur.w << endl;
		if(getfa(cur.u) == getfa(cur.v))continue;
		res += cur.w;
		merge(cur.u, cur.v);
	}
	
	return res;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges[i] = {u,v,w};
	}
	
	for(int i = 1; i <= k; i++){
		int tmp = 0;
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 0)
				tmp = j;
		}
		for(int j = 1; j <= n; j++){
			edges[i*n-n+j+m] = {tmp,j,a[i][j]};
		}
	}
	
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	
	cout << kruskal();
	
	return 0;
}

