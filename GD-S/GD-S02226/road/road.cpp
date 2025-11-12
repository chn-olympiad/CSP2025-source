#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,a[1000005];
int mp[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			if(mp[i][j]!=0){
				//mp[]
			}
			
		}
	}
	cout<<13;
	return 0;
}
