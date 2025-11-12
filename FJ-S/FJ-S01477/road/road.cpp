#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
struct edge
{
	long long u,v,w;
}x[114514];
long long jia[114514];
vector<long long> q[114514];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i].u>>x[i].v>>x[i].w;
		q[x[i].v].push_back(x[i].v);
		q[x[i].v].push_back(x[i].u);
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>jia[i];
		long long temp;
		for(long long j=1;j<=n;j++)
		{
			cin>>temp;
//			q[n+i].push_back(j);
//			q[j].push_back(n+i);
		}
	}
	for(long long i=1;i<=k;i++)
	ans+=jia[i];
	cout<<ans;
	return 0;
}

