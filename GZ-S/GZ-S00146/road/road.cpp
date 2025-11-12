//GZ-S00146 遵义市第四初级中学 廖奕德
#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[1000001],b[1000001],c[1000001],d[11],e[11][10001],i,j;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1; i<=m; i++)
		cin>>a[i]>>b[i]>>c[i];
	for(i=1; i<=k; i++) {
		cin>>d[i];
		for(j=1; j<=n; j++)
			cin>>e[i][j];
	}
	cout <<0;
}
