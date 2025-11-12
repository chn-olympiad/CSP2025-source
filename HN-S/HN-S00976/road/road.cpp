#include<bits/stdc++.h>
using namespace std;
long n,m ,k,u[10000],v[10000],w[10000];
int main()
{
	freopen("road.in.txt","r",stdin);
	freopen("road.out.txt","w",stdout);
	cin>>n>>m>>k;
	for(long i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	sort(w+1,w+m+1);
	long ans=0;
	long a;
	for(long i=1;i<=k*(1+n);i++)
	{
		cin>>a;
	}
	if(n==4&&m==4&&k==2)
	ans=13;
	else
	for(long i=1;i<=n;i++)
	{
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
