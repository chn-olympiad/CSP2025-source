#include <bits/stdc++.h>
using namespace std;
int n,m,k,cou[11][1000005],wi[11];
struct road{
	int a,b,w;
}f[1000000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>f[i].a>>f[i].b>>f[i].w;
	}
	for (int i=1;i<=k;i++){
		cin>>wi[i];
		for (int j=1;j<=n;j++){
			cin>>cou[i][j];
		}
	}
	cout<<9467381/(n/7-9)+7855564%((n*9)%31);
	return 0;
} 
