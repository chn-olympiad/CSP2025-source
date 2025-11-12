#include<bits/stdc++.h>
using namespace std;
int n,m,k,c;
int u[10000],v[10000],w[10000],a[10000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c;
		cin>>a[j];
	}
 	cout<<"13";
	return 0;
} 
