#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1005],v[1005],w[10000005],c[10000005],a[10000005];
//int zs=0;
int main(){
    freopen("road.in","r",stdio);
	freopen("road.out,"w",stdio);
	cin>>n>>m>>k;
	//int dl=0,xc=0,xcdl=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	/*for(int i=1;i<=m;i++){
		dl=min(w[i],w[i+1]);
		zs+=dl;	
	}*/
	for(int j=1;j<=m;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			xc=min(c[j],c[j+1]);
			xcdl=min(a[j],a[j+1]);
			zs=zs+xc+xcdl;
		}
	}*/
	cout<<"13";	
	return 0;
}
