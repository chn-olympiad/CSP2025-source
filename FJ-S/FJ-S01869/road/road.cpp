#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node 
{
	int u,v,w;
}e[1000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		cnt+=e[i].w;
	}
	cout<<cnt;
	return 0;
}
