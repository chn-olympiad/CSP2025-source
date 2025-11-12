#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7,M=1e6+7;
struct node1
{
	int u,v,w;
}a[M];
struct node
{
	int val,w[N];
}mapp[12];
int n,m,k,fa[N],cnt,ans;
bool cmp(node1 x,node1 y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
bool unio(int u,int v)
{
	int x=find(u),y=find(v);
	if(x==y) return 0;
	fa[x]=y;
	return 1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int i,j;
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=k;i++)
	{
		scanf("%lld",&mapp[i].val);
		for(j=1;j<=n;j++)
			scanf("%lld",&mapp[i].w[j]);
	}
	for(i=1;i<=m&&cnt<n-1;i++)
	{
		if(unio(a[i].u,a[i].v))
		{
			cnt++;
			ans+=a[i].w;
		}
	}
	cout << ans << endl;
	return 0;
}
