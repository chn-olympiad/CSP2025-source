#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int u[N],v[N],w[N],c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int ans=1e9;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ans=min(c[i],ans);
	}
	cout<<ans; 
	return 0;
} 
