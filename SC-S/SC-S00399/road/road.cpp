#include<bits/stdc++.h>
using namespace std;

long long M[10005][10005];
long long n,m,k;
long long x[15][10005];
long long va[100000000];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(M,1e9+5,sizeof(M));
	long long a,b,c;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		M[a][b]=c;
		M[b][a]=c;	
	}
	for(long long i=1;i<=k;i++)
	{
		for(long long j=0;j<=n;j++)
		{
			cin>>x[i][j];
		}
	}
	long long v;
	for(long long o=1;o<=k;o++)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i;j<=n;j++)
			{
				v=x[o][0]+x[o][i]+x[o][j];
				if(v<M[i][j])
				{
					M[i][j]=v;
					M[j][i]=v;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<M[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	long long an=0;
	long long kk=1;
	for(long long i=1;i<n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			va[kk]=M[i][j];
			kk++;
		}
	}
	sort(va+1,va+n*(n-1)/2+1);
	for(long long i=1;i<=n-1;i++)
	{
		an+=va[i];
	}
	cout<<an;
	return 0;
}