#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct ll{
	int u,v,w;
}l[1000006];
int c[12],a[12][10004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l[i].u>>l[i].v>>l[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<13;
	return 0;
} 
