#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,s,maxx,c[15],a[15][10005],mp[10015][10015];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
		s+=w,maxx=max(maxx,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(n==1) cout<<0;
	else if(m==n-1&&k==0)
		cout<<s;
	return 0;
}
