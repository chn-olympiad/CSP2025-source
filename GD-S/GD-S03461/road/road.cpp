#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[100000],v[100000],w[100000],ci[15][1000000];
int main(){
	freopen("road.in","r",stdin);


	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>ci[i][j];
		}
	}
	
	return 0;
}
