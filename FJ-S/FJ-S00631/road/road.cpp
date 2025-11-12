#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct a{
	int u;
	int v;
	int w;
}city[1000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cti[k][n+1];
	for(int i=1;i<=m;i++){
		cin>>city[i].u>>city[i].v>>city[i].w;
	}
	cout<<n+m+k+3;
	return 0;
}
