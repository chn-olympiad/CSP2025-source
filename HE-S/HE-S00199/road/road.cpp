#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[20005],c[15],minn[15],a[15][10005],plan[15],anss=1e18;
struct node
{
	long long u,v,w;
}edge[2000006];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
long long find(long long x)
{
	//return 1;
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
long long check()
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int l1=1,len=m,l2=m+1,ans=0;
	for(int i=1;i<=k;i++)
	{
		if(plan[i]==0)continue;
		ans+=c[i]+a[i][minn[i]];
		fa[m+i]=find(minn[i]);
		for(int j=1;j<=n;j++)edge[++len].u=m+i,edge[len].v=j,edge[len].w=a[i][j];
	}
	if(l2<=len)sort(edge+l2+1,edge+len+1,cmp);
	//cout<<len-l2<<endl;
	while(l1<=m&&l2<=len)
	{
		if(edge[l1].w<edge[l2].w)
		{
			if(find(edge[l1].u)!=find(edge[l1].v))
			{
				ans+=edge[l1].w;
				fa[find(edge[l1].u)]=find(edge[l1].v);
			}
			l1++;
		}
		else
		{
			if(find(edge[l2].u)!=find(edge[l2].v))
			{
				ans+=edge[l2].w;
				fa[find(edge[l2].u)]=find(edge[l2].v);
			}
			l2++;
		}
	}
	while(l1<=m)
	{
		if(find(edge[l1].u)!=find(edge[l1].v))
		{
			ans+=edge[l1].w;
			fa[find(edge[l1].u)]=find(edge[l1].v);
		}
		l1++;
	}
	while(l2<=len)
	{
		if(find(edge[l2].u)!=find(edge[l2].v))
		{
			ans+=edge[l2].w;
			fa[find(edge[l2].u)]=find(edge[l2].v);
		}
		l2++;
	}
	return ans;
}
void dfs(int step)
{
	if(step>k)
	{
		anss=min(check(),anss);
		return;
	}
	//cout<<111<<endl;
	dfs(step+1);
	plan[step]=1;
	dfs(step+1);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].w;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		minn[i]=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][minn[i]]>a[i][j])minn[i]=j;
		}
	}
	dfs(1);
	cout<<anss; 
	return 0;
}
