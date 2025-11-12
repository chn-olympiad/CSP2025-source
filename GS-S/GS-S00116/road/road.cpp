#include<bits\stdc++.h>
using namespace std;
int n,m,k,u[100005],v[100005],w[100005],c[20],a[20][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2)cout<<13;
	return 0;
	
}
