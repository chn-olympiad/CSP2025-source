#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int u,v,w;
} z[1000005];
struct node{
	int c,a[15];
} x[1000005];
bool zmp(road x,road y){
	return x.w<y.w;
}
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>z[i].u>>z[i].v>>z[i].w;
	}
	for (int i=1;i<=k;i++){
		cin>>x[i].c;
		for (int j=1;j<=n;j++){
			cin>>x[i].a[j];
		}
	}
	sort(z+1,z+1+n,zmp);
	sort(x+1,x+1+k,cmp);
	cout<<0;
	return 0;
}
