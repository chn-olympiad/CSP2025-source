#include<bits/stdc++.h>
using namespace std;

struct c{
	int u;
	int v;
	int w;
}a[10002];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int i;
	for(i=1;1<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	
	int j[12][10002];
	int x;
	for(i=1;i<=k;i++){
		for(x=1;x<=n;x++){
			cin>>j[i][x];
		}
	
	return 0;
}
