#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e6+10;
int n,m,k,c[20],f[15][10010],d[N],ans=0;
vector<PII>G[N];bool v[N];
void dij()
{
	memset(d,0x3f,sizeof d);memset(v,0,sizeof v);d[1]=0;
	priority_queue<PII,vector<PII>,greater<PII>>q;
	q.push({0,1});
	while(q.size())
	{
		int x=q.top().second;q.pop();
		if(v[x])continue;
		v[x]=1;
		for(auto i:G[x])
		{
			int y=i.first,w=i.second;
			if(d[y]>d[x]+w)
			{
				d[y]=d[x]+w;
				q.push({d[y],y});
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back({y,z});G[y].push_back({x,z});
	}
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&f[i][j]);
		sort(f[i]+1,f[i]+n+1);
		sum=f[i][1]+f[i][2];
	}
	dij();
	printf("%d\n",d[n]+d[n-1]-sum);
	return 0;
}
