#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,u[M],v[M],w[M],c[11],a[11][N],f[N][N];
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[k];
		for(int j=1;j<+n;j++){
			cin>>a[i][j];
		}
	}
	
	return 0;
}
