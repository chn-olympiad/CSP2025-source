#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[100000],v[100000],w[100000],a[10000][10000],c[10000],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	cout<<ans;
	return 0;
}
