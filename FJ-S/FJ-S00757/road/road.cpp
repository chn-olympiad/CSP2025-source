#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001],c[11],a[11][10001],b;
int main(){
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		sort(w+1,w+1+n);
		for(int i=1;i<m;i++){
			b+=w[i];
		}
		cout<<b;
		return 0;
	}
	return 0;
}
