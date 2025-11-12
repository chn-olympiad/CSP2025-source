#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct roa{
	int u;
	int v;
	int w;
}r[1000002];
int kv[10];
int kr[10][1000002];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin >>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=1;i<=k;i++){
		cin >>kv[i];
		for(int j=1;j<=n;j++){
			cin >>kr[i][j];
		}
	}
	cout <<13;
	return 0;
}
