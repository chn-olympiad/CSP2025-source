#include<bits/stdc++.h>
using namespace std;
vector<int> weid,weight,edge,Next,head;
int id=0;
int n;
priority_queue<pair<long long,int> > q;
long long d[10500];
bool visc[10005];//visited city/cities
bool visk[11];//visted country/countries
void add(int f,int t,int w)
{
	weight[++id]=w;
	edge[id]=t;
	Next[id]=head[f];
	head[f]=id;
}
void dij(void)
{
	memset(d,0x3f,sizeof(d));
	visc[1]=1;
	d[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(visc[x])
			continue;
		for(int i=head[x],z,y;i;i=Next[i])
		{
			y=edge[i];z=weight[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				if(x>n)
					visk[x-n]=1;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}
int main()
{
	freopen("road,in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m,k;
	cin>>n>>m>>k;
	weid.resize(k+1);
	weight.resize(2*k*n+m+3);
	edge.resize(2*n*k+m+3);
	Next.resize(2*k*n+m+3);
	head.resize(n+k+3);
	for(int i=1,f,t,w;i<=n;i++)
	{
		cin>>f>>t>>w;
		add(f,t,w);
		add(t,f,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>weid[i];
		for(int j=1,w;j<=k;j++)
		{
			cin>>w;
			add(n+i,j,w);
			add(j,n+i,w);
		}
	}
	dij();
	long long ans=0;
	for(int i=2;i<=n;i++)
	{
		ans+=d[i];
	}
	for(int i=1;i<=k;i++)
		if(visk[i])
			ans+=weid[i];
	cout<<ans;
}
