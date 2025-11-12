#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > e;
int a[10][10010];
int fa[1000010];
int c[10];
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0),cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int v,w,u;
		cin>>u>>v>>w;
		ans+=w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<w;
	return 0;
} 
