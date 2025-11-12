//code by 201012280925LSY
#include<bits/stdc++.h>
using namespace std;
const int N=10020,M=1100010;
const long long INF=1e18;
long long answer,n,m,k;
int fa[N],cnt;
struct town
{
	int price;
	int p[N];
}a[N];
struct edg
{
	int u,v,w;
}v[M];
void init()
{
	for(int i=1;i<=n+10;++i)fa[i]=i;
	return;
}
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool Merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		fa[fx]=fy;
		return 1;
	}
	return 0;
}
bool cmp(edg a,edg b)
{
	return a.w<b.w;
}
int flag=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if(!k)
	{
		for(int i=1;i<=m;++i)
		{
			int u,V,w;
			cin>>u>>V>>w;
			v[i].u=u;
			v[i].v=V;
			v[i].w=w;
		}
		sort(v+1,v+m+1,cmp);
		for(int i=1;i<=m;++i)
		{
			if(Merge(v[i].u,v[i].v))
			{
				answer+=v[i].w;
			}
		}
		cout<<answer<<"\n";	
		return 0;
	}
	for(int i=1;i<=m;++i)
	{
		int u,V,w;
		cin>>u>>V>>w;
		v[i].u=u;
		v[i].v=V;
		v[i].w=w;
	}
	cnt=m;
	for(int i=1;i<=k;++i)
	{
		cin>>a[i].price;
		flag+=a[i].price;
		for(int j=1;j<=n;++j)
		{
			cin>>a[i].p[j];
		}
	}
	if(!flag)
	{
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=n;++j)
			{
				v[++cnt].u=i+n;
				v[cnt].v=j;
				v[cnt].w=a[i].p[j];
			}
		}
		init();
		sort(v+1,v+cnt+1,cmp);
		for(int i=1;i<=cnt;++i)
		{
			if(Merge(v[i].u,v[i].v))
			{
				answer+=v[i].w;
			}
		}
		cout<<answer;
		return 0;
	}
	answer=INF;
	long long sum=0;
	for(int i=0;i<(1<<k);++i)
	{
		cnt=m;
		for(int j=1;j<=k;++j)
		{
			if((1<<(j-1))&i)
			{
				for(int l=1;l<=n;++l)
				{
					v[++cnt].u=j+n;
					v[cnt].v=l;
					v[cnt].w=a[j].p[l];
				}
				sum+=a[j].price;
			}
		}
		init();
		sort(v+1,v+cnt+1,cmp);
		for(int i=1;i<=cnt;++i)
		{
			if(Merge(v[i].u,v[i].v))
			{
				sum+=v[i].w;
			}
		}
		answer=min(answer,sum);
		sum=0;
	}
	cout<<answer;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

