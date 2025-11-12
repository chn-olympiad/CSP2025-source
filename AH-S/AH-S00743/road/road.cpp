#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0,minn=0x7fffffff;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	minn=min(minn,sum);
	sum=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int x;
			cin>>x;
			sum+=x;
		}
		minn=min(minn,sum);
		sum=0;
	}
	cout<<minn;
	return 0;
}
