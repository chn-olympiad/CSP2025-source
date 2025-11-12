#include<iostream>
using namespace std;
int u[200005],v[200005],w[200005],a[200005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int less=2e5;
		if(w[i]<=less) less=w[i];
		cout<<w[i];
	}
}
