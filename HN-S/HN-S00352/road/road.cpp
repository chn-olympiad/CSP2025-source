#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int v,u,w,a,c,s=0;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		s+=w;
	}  
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
	}
	cout<<s;
	return 0;
}
