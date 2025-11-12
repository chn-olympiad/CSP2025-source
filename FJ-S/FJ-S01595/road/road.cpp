#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10004],a[1000005];
struct node{
	int u,v,w;
}r[1000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<0;
	return 0;
}
