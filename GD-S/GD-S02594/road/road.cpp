#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k;
int u[N],v[N],w[N],c[15],a[15][15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i]; 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=5;j++)
		cin>>a[i][j];
	}
	
	return 0;
}
