#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u,v,w;
int a[1010];
int b[11];
int minn=INT_MAX;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u>>v>>w;
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++) cin>>a[i];
		minn=min(minn,b[i]);
	}
	cout<<minn;
	return 0;
}

