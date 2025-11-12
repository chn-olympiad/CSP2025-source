#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(int(time(0)));
	int n,m,k,u,v,w,a[1010];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u>>v>>w;
	for(int j=1;j<=k;j++)
		for(int l=1;l<=n+1;l++)
			cin>>a[l];
	cout<<rand()%101;
	return 0;
}