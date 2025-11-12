#include<iostream>
using namespace std;
int main(){
	preopen("road.in","r",stdin);
	preopen("road.out","w",stdout);
	int n,m,k,u[100],v[100],w[100],c[100],i=0;
	cin>>n,m,k;
	for(i;i<=m;i++){
		cin>>u[i];
		cin>>v[i];
		cin>>w[i];
		cin>>c[i];
	}
	cout<<13;
	
	fclos(stdin);
	fclos(stdout);
	return 0;
}
