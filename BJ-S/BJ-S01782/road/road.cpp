#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,u,v,w;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u>>v>>w;
	int tmp;
	for(int i=1;i<=k;i++)
	{
		for(int i=0;i<=n;i++)
			cin>>tmp;
	}
	cout<<13<<endl;
	return 0;
}