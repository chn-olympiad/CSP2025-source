#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct M
{
	int u,v,w;
};
M a[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
		
	return 0;
}
