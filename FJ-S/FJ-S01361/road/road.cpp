#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[1000006][1000006];
struct vlg{
	int c;
	int a[10004];
}vg[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,wl;
		cin>>u>>v>>wl;
		w[u][v]=wl;
		w[v][u]=wl;
	}
	for(int i=1;i<=k;i++){
		cin>>vg[i].c;
		for(int j=1;j<=n;j++){
			cin>>vg[i].a[j];
		}
	}
	return 0;
}
