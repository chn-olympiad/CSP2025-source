#include <bits/stdc++.h>
using namespace std;
int n,m,k,cmt=0,c[15],d[15][10005],fa[10015];
long long ans=1e18;
bool flag[10015];
struct node
{
	int u,v,w;
}road[2000005];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal()
{
	long long sum=0;
	int cnt=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int uu=road[i].u,vv=road[i].v,ww=road[i].w;
		if(flag[uu]||flag[vv]||find(uu)==find(vv)) continue;
		fa[fa[uu]]=vv;
		sum+=ww;
		cnt++;
		if(cnt==n+k-cmt-1)
		{
			for(int j=n+1;j<=n+k;j++)
			{
				if(!flag[j]) sum+=c[j-n];
			}
			ans=min(ans,sum);
			return;
		}
	}
}
void solve(int now)
{
	if(now==k+1)
	{
		kruskal();
		return;
	}
	solve(now+1);
	flag[n+now]=true;
	cmt++;
	solve(now+1);
	flag[n+now]=false;
	cmt--;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		cin >> road[i].u >> road[i].v >> road[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> d[i][j];
			road[++m].u=n+i;
			road[m].v=j;
			road[m].w=d[i][j];
		}
	}
	sort(road+1,road+m+1,cmp);
	solve(1);
	cout << ans << endl;
	return 0;
}
