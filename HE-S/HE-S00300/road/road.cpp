#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int hh[N];
int a[12][N];
int b[12];
struct lu
{
	int z,y,f;
}m1[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>m1[i].z>>m1[i].y>>m1[i].f;
		hh[i]=m1[i].f;
	}
	int sum=0;
	if(k==0)
	{
		sort(hh+1,hh+1+m);
		
		for(int i=1;i<=n;i++)
		{
			sum+=hh[i];
		}
		
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			cin>>b[i];
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j]; 
			}
		}
	}
	cout<<sum;
	return 0;
}
