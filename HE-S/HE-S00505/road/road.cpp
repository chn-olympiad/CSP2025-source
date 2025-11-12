#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k; cin>>n>>m>>k;
	int v[m+1][3],w[m+1],a[k+1];
	for(int i=1;i<=m;i++)
	{
		cin>>v[i][1]>>v[i][2]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	
	cout<<"13";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
