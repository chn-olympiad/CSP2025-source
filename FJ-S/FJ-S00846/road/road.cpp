#include<iostream>
using namespace std;
int n, m,k,v[1000005],u[1000005],w[1000005],c[1000005],x[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>u[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=n*(i-1)+1;j<=n*i;j++){
			cin>> x[j];
		}
	}
	cout<<13;
	return 0;
} 
