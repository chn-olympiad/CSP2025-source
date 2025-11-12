#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct l{
	int u,v,w;
}uvw[M];
int n,m,k;
int c,a[15][N];

int main(){
	freopen( "road.in","r",stdin );
	freopen( "road.out","w",stdout );
	cin >> n >> m >> k;
	for( int i=1;i<=m;i++ ){
		cin >> uvw[i].u >> uvw[i].v >> uvw[i].w;
	}
	cin >> c;
	for( int i=1;i<=k;i++ ){
		for( int j=1;j<=n;j++ ){
			cin >> a[i][j];
		}
	}
	
	return 0;
}
