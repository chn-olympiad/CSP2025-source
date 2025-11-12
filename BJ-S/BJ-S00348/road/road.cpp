#include <bits/stdc++.h>
using namespace std;
vector <pair <int,int> > a[10050];
long long b[10050];
int v[10050];
queue <int> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++)
	{
		int g;
		cin>>g;
		ans+=g;
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			a[n+i].push_back({j,x});
			a[j].push_back({n+i,x});
		}
	}
	q.push(1);
	v[1]=1;
	int cnt=n+k-1;
	for(int i=2;i<=n+k;i++)
	{
		b[i]=0x3f3f3f3f3f3f3f3f;
	}
	while(cnt)
	{
		int s=q.front();
		q.pop();
		for(auto i=a[s].begin();i!=a[s].end();i++)
		{
			int e=(*i).first,w=(*i).second;
			if(b[e]>w)
			{
				b[e]=w;
			}
		}
		long long mi=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n+k;i++)
		{
			if(v[i]!=1)mi=min(mi,b[i]);
		}
		for(int i=1;i<=n+k;i++)
		{
			if(b[i]==mi&&v[i]!=1)
			{
				cnt--;
				ans+=b[i];
				v[i]=1;
				q.push(i);
			}
		}
	}
	cout<<ans;
	return 0;
}
