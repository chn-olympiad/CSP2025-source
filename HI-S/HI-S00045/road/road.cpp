#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v>>w[i];
	}
	for(int i=1;i<=m+1;i++){
		int x;
		cin>>x;
	}
	sort(w+1,w+n+1);
	int cnt=0;
	for(int i=1;i<=n-1;i++){
		cnt+=w[i];
	}
	cout<<cnt;
	return 0;
}
