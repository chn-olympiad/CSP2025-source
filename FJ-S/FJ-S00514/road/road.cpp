#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long minn=INT_MAX;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		long long cnt=0;
		int a;
		cin>>a;
		cnt+=a;
		for(int j=1;j<=n;j++){
			int k;
			if(j==1) continue;
			cin>>k;
			cnt+=k;
		}
		minn=min(minn,cnt);
	}
	cout<<minn;
	return 0;
} 
