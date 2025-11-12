#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,c[1000010],d[1000010],u,v,w,a[1000010][1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		cin>>u>>v>>w;
		a[u][v]=w;
		s+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>d[i];
	}
	cout<<s;	
	return 0;
}
