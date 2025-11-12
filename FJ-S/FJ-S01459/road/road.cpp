#include<bits/stdc++.h>
using namespace std;
struct bin{
	int from,to,d;
}a[200001];
bool v[200001];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long> > >q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		a[i].from=x;a[i].to=y;a[i].d=z;
		q.push(make_pair(z,i));
	}
	for(int i=1;i<=k;i++)
	{
		int r;
		for(int j=1;j<=n+1;j++)
		{
			scanf("%d",&r);
		}
	}
	long long sum=0,ans=0;
	while(!q.empty())
	{
		if(sum==n)break;
		long long x=q.top().first;
		long long y=q.top().second;
		q.pop();
		if(v[a[y].from]&&v[a[y].to])
		{
			continue;
		}
		else
		{
			if(v[a[y].from])
			{
				sum+=1;
				ans+=x;
				v[a[y].to]=1;
			}
			else if(v[a[y].to])
			{
				sum+=1;
				ans+=x;
				v[a[y].to]=1;
			}
			else
			{
				sum+=2;
				ans+=x;
				v[a[y].from]=1;
				v[a[y].to]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}