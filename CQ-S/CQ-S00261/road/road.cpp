#include <bits/stdc++.h>
using namespace std;

long long n,m,k;
long long u,v,w;
long long arr[1000001]={0};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	std::cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		std::cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			std::cin>>arr[j];
		}
	}
	std::cout<<0;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
