#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,fa[10010],cnt,ans;
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void hb(int x,int y)
{
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}

struct st 
{
	int u,v,w;
}a[1000010];
bool cmp(st x,st y)
{
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
	for(int i=1;i<=m;i++)
	{
		int n1,n2,n3;
		cin>>n1>>n2>>n3;
		a[++cnt]={n1,n2,n3};
		
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu!=fv)
		{
			fa[fu]=fv;ans+=a[i].w;
		}
	}
	cout<<ans;
}
	else cout<<0;
	
	return 0;
}
