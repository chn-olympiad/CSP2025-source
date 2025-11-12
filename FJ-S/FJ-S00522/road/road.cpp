#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int u,v,w;
	cin>>n>>m>>k;
	int c;
	int a[1123456];
	int ans=0;
	int p[1123456];
	int l[1123456];
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(abs(u-v)==1){
			l[min(u,v)]=w;
		}	
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=c+a[i]+a[i+1];
		}
	}
	for(int i=1;i<n;i++){
		ans+=l[i];
	}
		cout<<ans;
	return 0;
}
