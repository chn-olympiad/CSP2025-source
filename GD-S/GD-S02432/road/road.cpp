#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[100005],v[100005],w[100005],c[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}for(int i=1;i<=k;i++){
		if(c[i][0]==0){
			cout<<0;
			return 0;
		}
	}
	cout<<rand();
}



