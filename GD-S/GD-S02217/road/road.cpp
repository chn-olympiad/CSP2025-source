#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int u[1000005],v[1000005],w[1000005],c[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n+1;i++){
		cin>>c[i];
	}
	
	return 0;
}
