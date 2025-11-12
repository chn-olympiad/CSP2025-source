#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[9999],v[9999],w[9999];
int a[9999];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++)
	{
		cin>>a[i];
	}
	return 0;
}
