#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,c[20010],fa[20010],now[20],sum,ans;
vector<long long> id;
long long ff(long long x)
{
	if(fa[x]==x) return x;
	fa[x]=ff(fa[x]);
	return fa[x];
}
struct node
{
	long long x,y,z;
}v[20010],e[1000010],a[20][20010];
bool cmp(node aa,node bb)
{
	return aa.z<bb.z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>e[i].x>>e[i].y>>e[i].z;
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			a[i][j].x=n+i;
			a[i][j].y=j;
			cin>>a[i][j].z;
		}
		sort(a[i]+1,a[i]+1+n,cmp);
	}
	sort(e+1,e+1+m,cmp);
	for(long long i=1;i<=n;i++) fa[i]=i;
	for(long long i=1;i<=m;i++)
	{
		if(ff(e[i].x)==ff(e[i].y)) continue;
		v[++cnt]=e[i];
		fa[ff(e[i].y)]=ff(e[i].x);
		ans+=e[i].z;
		if(cnt==n-1) break;
	}
	for(long long i=0;i<(1<<k);i++)
	{
		long long num=0;
		sum=0;
		id.clear();
		for(long long j=1;j<=k;j++)
		{
			if((1<<(j-1))&i)
			{
				id.push_back(j);
				num++;
				sum+=c[j];
			}
		}
		for(long long j=1;j<=n+k;j++) fa[j]=j;
		for(long long j=1;j<=k;j++) now[j]=0;
		long long cnt=0,now0=0;
		while(cnt<n+num-1)
		{
			long long mx=0;
			for(long long x:id)
			{
				if(now[x]<n && (mx==0 || a[x][now[x]+1].z<a[mx][now[mx]+1].z))
				{
					mx=x;
				}
			}
			if(mx==0 || (now0<n-1 && v[now0+1].z<a[mx][now[mx]+1].z))
			{
				now0++;
				if(ff(v[now0].x)==ff(v[now0].y)) continue;
				fa[ff(v[now0].y)]=ff(v[now0].x);
				sum+=v[now0].z;
				cnt++;
				if(cnt==n+num-1) break;
				continue;
			}
			now[mx]++;
			if(ff(a[mx][now[mx]].x)==ff(a[mx][now[mx]].y)) continue;
			fa[ff(a[mx][now[mx]].y)]=ff(a[mx][now[mx]].x);
			sum+=a[mx][now[mx]].z;
			cnt++;
			if(cnt==n+num-1) break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
