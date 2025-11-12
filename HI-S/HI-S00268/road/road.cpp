#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
#define ll long long
ll n,bz,k,ans,a2[20][maxn],key,m,fa[maxn];
struct sj
{
	int x,y,w;
}a1[maxn];
bool cmp(sj x,sj y)
{
	return x.w<y.w;
}
int find(int f)
{
	if(fa[f]!=f)
	{
		return find(fa[f]);
	}
	return f;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a1[i].x,&a1[i].y,&a1[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			scanf("%d",&a2[i][j]);
			if(a2[i][j]==0&&find(i+n)==i+n&&j!=0)
			{
				fa[find(i+n)]=find(j);
			}
			else if(a2[i][j]==0&&j!=0)
			{
				fa[find(j)]=find(i+n);
			}
			else if(j!=0)
			{
				m++;
				a1[m].x=n+i;a1[m].y=j;a1[m].w=a2[i][j];
			}
		}
	}
	sort(a1+1,a1+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=a1[i].x,fy=a1[i].y;
		if(find(fx)!=find(fy))
		{
			ans+=a1[i].w;
			fa[find(fx)]=find(fy);
		}
	}
	cout<<ans;
	return 0;
 } 
