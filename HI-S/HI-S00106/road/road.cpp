#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[100001],v[100001],w[100001];
long long c[11],a[11][10001],mi,s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=n-1;i++)
	{
		s+=w[i];
	}
	cout<<s;
	return 0;
}
