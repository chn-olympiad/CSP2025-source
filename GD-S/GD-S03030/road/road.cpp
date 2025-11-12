#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[100010],vis[100010],ans=0,cnt;
struct node
{
	int u,v,w;
}a[100050];
bool cmp(node s,node b)
{
	return s.w<b.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void work()
{
	for(int i=0;i<=n;i++) fa[i]=i;
	int sum=0;
	for(int i=1;i<=cnt;i++)
	{
		int x=a[i].u,y=a[i].v;
		cout<<find(x)<<" "<<find(y)<<endl;
		if(find(x)!=find(y))
		{
			fa[x]=y;
			sum++;
			ans+=a[i].w;
		}
		if(sum>=n) break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[++cnt].u>>a[cnt].v>>a[cnt].w;
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			int z;
			cin>>z;
			a[++cnt].u=0,a[cnt].v=j,a[cnt].w=z;
		}
	}
	sort(a+1,a+cnt+1,cmp);for(int i=1;i<=cnt;i++) cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
	work();
	cout<<ans;
}
/*
4 4 1
1 2 3
2 3 3
4 1 3
3 4 1
0 1 1 5 6
*/
