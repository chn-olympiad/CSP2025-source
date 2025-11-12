#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long sum=0;
int u,v,w;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	return 0;
}

