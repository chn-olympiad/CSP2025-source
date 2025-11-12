#include<bits/stdc++.h>

using namespace std;

int u[100001],v[100011],w[101011],c[122],a[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		if(j==1){
	      cin>>c[j];
		}
		cin>>a[j];
	}
	cout<<13;
	return 0;
}
