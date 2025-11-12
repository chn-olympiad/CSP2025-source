#include <iostream>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u[1000],v[1000],w[1000],a[1000][1000],c[1000],num=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<m;i++){
	    num+=w[i];
	}
	cout<<num;
}
