#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10005];
struct node{
	int u,v,w;
}a[1000005]
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
