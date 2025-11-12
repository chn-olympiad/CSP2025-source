#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,next;
	long long val;
};
vector<edge> e;
int n,m,k,cnt;
long long a[10001],size[10001];
int fa[10001],head[10001];
long long ans;
bool cmp(edge x,edge y)
{
	return x.val<y.val;
}
void add(int x,int y,long long v)
{
	edge ed;
	ed.from=x;
	ed.to=y;
	ed.val=v;
	ed.next=head[x];
	e.push_back(ed);
	head[x]=cnt++;
}
int f(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=f(fa[x]);
}
void unionset(int x,int y)
{
	int fx=f(x),fy=f(y);
	if(fx==fy)
		return;
	if(size[fx]>size[fy])
		swap(fx,fy);
	fa[fx]=fy;
	size[fy]+=size[fx];
}
bool check()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		if(fa[i]==i)
			sum++;
	return sum-1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		long long v;
		scanf("%d%d%lld",&x,&y,&v);
		add(x,y,v);
		add(y,x,v);
	}
	for(int i=1;i<=k;i++)
	{
		int w;
		cin>>w;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				add(i,j,a[i]+a[j]);
				add(j,i,a[i]+a[j]);
			}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<cnt;i++)
		if(check())
		{
			int u=e[i].from,v=e[i].to;
			if(f(u)!=f(v))
			{
				unionset(u,v);
				ans+=e[i].val;
			}
		}
	cout<<ans;
	return 0;
}