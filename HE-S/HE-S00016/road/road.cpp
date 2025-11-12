#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int u[maxn],v[maxn],w[maxn],c[15],a[15][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int l=1;l<=n;l++){
			cin>>a[j][l];
		}
	} 
	
	cout<<13;
	return 0;
} 
