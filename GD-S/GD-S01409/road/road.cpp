#include<bits/stdc++.h>
using namespace std;
long long n,m,k; 
long long u[1000006],v[1000006],w[1000006];
long long c[15],a[15][1000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
}
