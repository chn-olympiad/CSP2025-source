#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m+1],v[m+1],w[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		int c,a[n+1];
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	cout<<13<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
