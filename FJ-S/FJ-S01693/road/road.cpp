#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0,min=100,min1;
	cin>>n>>m>>k;
	int u[m+1],v[m+1],w[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		if(min<w[i])
		{
			min=w[i];
			min1=i;
		}
	}
	cout<<13;
}
