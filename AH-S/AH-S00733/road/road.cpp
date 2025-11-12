#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,z,l,cost,dis[1005][1005],vi[1005];
bool vis[1005][1005],ne[1005][1005];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> z;
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		dis[u][v]=w,ne[u][v]=1;
		dis[v][u]=w,ne[v][u]=1;
	}
	l=n;
	for(int i=1; i<=z; i++) {
		int c;
		cin >> c;
		vi[++l]=c;
		for(int j=1; j<=n; j++) {
			int cc;
			cin >> cc;
			dis[l][j]=cc,ne[l][j]=1;
			dis[j][l]=cc,ne[j][l]=1;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=l; j++) {
		    if(i==j) continue;
		    for(int k=1; k<=n; k++) {
				if(i==k||j==k) continue;
				if(dis[i][j]+dis[j][k]<dis[i][k]) {
					dis[i][k]=dis[i][j]+dis[j][k];
					if(vi[j]) cost+=vi[j],vi[j]=0;
					if(ne[i][j]&&!vis[i][j]) 
						vis[i][j]=1,cost+=dis[i][j];
					if(ne[j][k]&&!vis[j][k]) 
						vis[j][k]=1,cost+=dis[j][k]; 
				}
			}	
		}
	}
	cout << cost;
	return 0;
}
