#include<bits/stdc++.h>
using namespace std;
int sum=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			
			sum+=w;
		}
		cout<<sum;
	}
	else
	{
		cout<<0;
	}
}
