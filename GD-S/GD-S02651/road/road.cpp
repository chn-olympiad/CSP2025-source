#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
long long ans;
bool flag[1010];
struct node1{
	int u,v,w;
}p[1010];
struct node2{
	int a[1010],c;
}q[10];
bool cmp(node1 x,node1 y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
	}
	for(int l=1;l<=k;++l)
	{
		scanf("%d",&q[l].c);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&q[l].a[i]);
		}
	}
//	if(k==0)
	{
		sort(p+1,p+1+m,cmp);
//		for(int i=1;i<=m;i++)cout<<p[i].u<<' '<<p[i].v<<' '<<p[i].w<<endl;
//		cout<<endl;
		for(int i=1;i<=m&&cnt<n;i++)
		{
			if(flag[p[i].u]&&flag[p[i].v])continue;
			if(!flag[p[i].u])flag[p[i].u]=true,cnt++;
			if(!flag[p[i].v])flag[p[i].v]=true,cnt++;
			ans+=p[i].w;
		}
		printf("%lld",ans);
	}
	return 0;
}
