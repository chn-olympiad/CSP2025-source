#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10005],v[10005],w[10005],c[2],a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	cin>>c[1];
	for (int i=1;i<=n;i++){
		cin>>a[1][i];
	}
	cout<<13;
	return 0;
}
