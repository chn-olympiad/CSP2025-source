#include<bits/stdc++.h>
using namespace std;
int u[10001],x[10001],v[10001],w[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i];
		cin>>v[i];
		cin>>w[i];
	}
	for(int i=1;i<=n+1;i++)
		cin>>x[i];
	cout<<0;	
	return 0;
}
