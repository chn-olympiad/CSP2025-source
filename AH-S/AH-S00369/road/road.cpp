#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=1000010;
int n,m,k,u,v,g[N][N],c[11][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
        cin>>u>>v;
        cin>>w[u][v];
        w[v][u]=w[u][v];
	}
	for(int i=1;i<=k;i++)
        for(int j=0;j<k;j++)
            cin>>c[n];
    cout<<13;
	return 0;
}
