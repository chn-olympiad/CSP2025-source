#include<bits/stdc++.h>
using namespace std;
long long n,m,k,i,u,v,w,c[10009][10009];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)cin>>u>>v>>w;
	for(i=1;i<=k;i++){
		for(j=1;j<=n+1;j++)cin>>c[i][j];
	}
	cout<<n+m+k;
}
