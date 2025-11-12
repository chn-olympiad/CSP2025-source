#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005];
int a[15][10005];
int fa[10015];
ont find(int x){
	if(x==fa[x])return x;
	find(fa[x]=find(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>m[i];
		ans+=m[i];
	}
	cout<<ans;
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n;i++){
			cin>>a[i][j];
		}
	}
	 
	return 0; 
}

