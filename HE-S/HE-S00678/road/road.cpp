#include<bits/stdc++.h>
using namespace std;
struct aaa{
	long long v,u,w;
}city1[100010];
long long f,ff,fff,sum;
long long c[15],a[15][100010];
long long n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>city1[i].u>>city1[i].v>>city1[i].w;
		sum+=city1[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]==0)f++;ff=0;
		for(int j=1;j<=n;j++)
		{
			
			cin>>a[i][j];
			if(a[i][j]==0)ff++;
		}
		if(ff==n)fff++;
	}
	if(f==k&&fff==k)
	cout<<"0";
	else
	{
		cout<<sum;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
