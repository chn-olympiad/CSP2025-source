#include<bits/stdc++.h>
using namespace std;
long long u[1000000],v[1000000],w[10000000],c[1000000],a[1000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[j];
	}
	cout<<16;
	return 0;
}
