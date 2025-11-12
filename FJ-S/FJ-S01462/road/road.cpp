#include<bits/stdc++.h>
using namespace std;
int n,m,k,xi=1000000000,sum=0;
int u[12312],v[12312],w[12312],as[123][123],big=-1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(w[i]>big){
			big=w[i];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m;j++){
			cin>>as[i][j];
			if(as[i][j]<xi){
				xi=as[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(w[i]!=big){
			sum+=w[i];
		}
	}
	cout<<sum;
	return 0;
} 

