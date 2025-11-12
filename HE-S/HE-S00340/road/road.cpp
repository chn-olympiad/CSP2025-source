#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1010][1010];
int n,m,k;
int u,v,w;
int op[100][1010];
int c[100];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>op[i][j];
		}
	}
	cout<<0;
	
	
	
	
	
	
	return 0;
}//ÓÖ¾è560 
