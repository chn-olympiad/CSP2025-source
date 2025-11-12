#include<bits/stdc++.h>
using namespace std;
int u[1000003],v[1000003],w[1000003];
int a[11][10003];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[j][i]);
		}
	}
		long long int sum=0; 
		for(int i=1;i<=m;i++)
		{
			sum=sum+w[i];
		}
		cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
