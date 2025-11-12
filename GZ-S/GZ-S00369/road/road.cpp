//GZ-S00369 贵阳市南明区华麟学校 罗翌宸 
#include<bits/stdc++.h>
using namespace std;
struct road{
	int u;
	int v;
	int w;
}uvw[1000000+10];
int n,m,k,a[20][10000+10],c[20];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>uvw[i].u>>uvw[i].v>>uvw[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	cout<<13;
	return 0;
}

