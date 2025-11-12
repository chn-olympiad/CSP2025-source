#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
#define int long long
int a[15][N];
int c[15];
int g[N][N];
bool st[15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	memset(g,-1,sizeof g);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			int res=LLONG_MAX;
			for(int p=1;p<=k;p++){
				res=min(a[p][i]+a[p][j],res);
			}
			if(g[i][j]==-1||g[j][i]==-1)ans+=res;
			else ans+=min(res,g[i][j]);
		}
	}
	cout << ans;
	return 0;
}
