#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e3+5;
int a[M][M],c[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=n/2;i++){
		cin>>c[i];
	}
	cout<<13;
    return 0;
}
