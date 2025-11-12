#include<bits/stdc++.h>
using namespace std;
int w[100001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
	} 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int a;
			cin>>a;
		} 
	}
	sort(w+1,w+1+m);
	for(int i=1;i<n;i++){
		ans+=w[i];
	} 
	cout<<ans;
	return 0;
}

