#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int t[2000001],tmp[2000001];
int find(int x)
{
	if (t[x]==x) return x;
	return t[x]=find(t[x]);
}
struct node
{
	int u,v;
	long long w;
}e[2000001];
int cnt=0;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	if (k==0)
	{
		long long sum=0;
		for (int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			sum+=w;
		}
		printf("%lld",sum);
		return 0;
	}
	for (int i=1;i<=n;i++) t[i]=i;
	for (int i=1;i<=m;i++)
	{
		++cnt;
		scanf("%d %d %lld",&e[cnt].u,&e[cnt].v,&e[cnt].w);
	}
	for (int i=1;i<=k;i++)
	{
		int a,z=0;
		scanf("%d",&a);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&tmp[i]);
			if (tmp[i]==0) z=i;
		}
		for (int i=1;i<=n;i++)
		{
			if (i==z) continue;
			++cnt;
			e[cnt].u=z;
			e[cnt].v=i;
			e[cnt].w=tmp[i];
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int res=0;
	long long ans=0;
	for (int i=1;i<=cnt&&res<n-1;i++)
	{
		int x=find(e[i].u),y=find(e[i].v);
		if (x==y) continue;
		res++;
		t[x]=y;
		ans+=e[i].w;
	}
	cout<<ans;
	return 0;
}
//*** have no egg
