#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000086],v[1000086],w[1000086],r[10086][10086],c[11],a[11][1000086];
bool b=1;
int main(){
	cin>>n>>m>>k; 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		r[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)b=0;
		}
		if(b==1){
			cout<<0;
			break;
		}
	}
	
	return 0;
}
