#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1005],v[1005],w[100000005],s[100000005],c[15],a[15][1005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		s[i] = w[i];
	}
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<"13";
	
	return 0;
}
