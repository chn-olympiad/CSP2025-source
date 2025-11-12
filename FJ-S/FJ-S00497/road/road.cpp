#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000009];
int mon[1009][1009];
long long ans; 
int main(){
	freopen("read.in","r",stdin);
	freopen("read.out","w",stdout);
	cin>>n>>m>>k;
	memset(mon,INT_MAX,sizeof mon);
	for(int i = 1;i<=n;i++){
		mon[i][i] = 0;
		
	}
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mon[u][v] = mon[v][u] = min(mon[u][v],min(w,mon[v][u]));
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
				ans+=mon[i][j];
		}
	}
	cout<<ans;
	return 0;
}
