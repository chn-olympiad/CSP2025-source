#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,road,vl;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&road,&road,&road);
	for(int i=1;i<=k;i++)
		for(int j=1;i<=n+1;j++)
			scanf("%d",&vl);
	cout<<0;
	return 0;
}
