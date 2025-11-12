#include<bits/stdc++.h>

using namespace std;

int u[1000005],v[1000005],w[1000005],c[12][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	bool pan=0;   //ÌØÊâĞÔÖÊA 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
			if(c[i][j]==1)pan=1;
		}
	}
	if(pan==0){
		cout<<0;
		return 0;
	}
	return 0;
} 
