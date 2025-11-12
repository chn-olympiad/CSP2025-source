#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+15,M=1e6+5;
int n,m,k;
bool used[15];
ll a[15][N],c[15],ans=0;
struct Edge
{
	int u,v;
	ll w;
}mp[M];
bool cmp(Edge q,Edge p)
{
	return q.w<p.w;
}
int fa[N];
int Find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=Find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>mp[i].u>>mp[i].v>>mp[i].w;
	bool zero_check=1;
	c[0]=0;
	for(int i=1;i<=k;i++)
	{
		ll minn=1e9,minx,sminn=1e9,sminx;
		cin>>c[i];
		if(c[i]) zero_check=0;
		used[i]=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]<minn) sminn=minn,sminx=minx,minn=a[i][j],minx=j;
			else if(a[i][j]<sminn) sminn=a[i][j],sminx=j;
			if(a[i][j]) zero_check=0;
		}
		mp[++m].u=minx;mp[m].v=sminx;mp[m].w=minn+sminn+c[i];
	}
	if(zero_check)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(mp+1,mp+1+m,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++)
	{
		int fu=Find(mp[i].u),fv=Find(mp[i].v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			cnt++;
			int minx=0;
			ll minn=mp[i].w;
			for(int j=1;j<=k;j++)
			{
				if(minn>a[j][mp[i].u]+a[j][mp[i].v]+c[j]*used[j])
				{
					minn=a[j][mp[i].u]+a[j][mp[i].v]+c[j]*used[j];
					minx=j;
				}
			}
			ans+=minn,used[minx]=0;
			if(cnt==n) break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
