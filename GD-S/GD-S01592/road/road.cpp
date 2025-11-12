#include<iostream>
using namespace std;
int n,m,k;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	long long sum = 0LL;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		
		sum+=w*1LL;
	}
	
	cout<<sum;
	return 0;
}
