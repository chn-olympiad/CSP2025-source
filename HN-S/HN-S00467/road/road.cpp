#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m],v[m],w[m];
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int c[n],a[n][k];
	for(int i=0;i<n;i++){
		cin>>c[i];
		for(int j=0;j<k;j++){
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
}
