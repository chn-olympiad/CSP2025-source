#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005];
struct edge
{
	int u,v,z;
}a[1000005];
bool cmp(edge a,edge b){return a.z<b.z;}
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].z);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+m+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1)break;
		if(find(a[i].u)!=find(a[i].v))
		{
			fa[find(a[i].u)]=find(a[i].v);
			ans+=a[i].z;
			cnt++;
		}
	}
	printf("%d",ans);
	return 0;
}
