#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,a[11][10001],c[11],u,v,w,sumc=0,fa[20000],cnt=0,p[10],ans2=1e18;
struct b
{
	ll fr,tt,ff;
}q[2000000],d[2000000];
bool cmp(b x,b y)
{
	return x.ff<y.ff;
}
int Find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	fa[x]=Find(fa[x]);
	return fa[x];
}
void solve1()
{
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cnt++;
			q[cnt].fr=i+n,q[cnt].tt=j,q[cnt].ff=a[i][j];
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	sort(q+1,q+1+cnt,cmp);
	ll ans=0;
	for(int i=1;i<=cnt;i++)
	{
		b k=q[i];
		if(Find(k.fr)==Find(k.tt))
		{
			continue;
		}
		ans+=k.ff;
		fa[Find(k.tt)]=Find(k.fr);
	}
	cout<<ans;
	return;
}
void dfs(int x,int sum)
{
	if(x==k+1)
	{
		ll ncnt=cnt,ans=sum;
		for(int i=1;i<=k;i++)
		{
			if(p[i]==1)
			{
				for(int j=1;j<=n;j++)
				{
					ncnt++;
					q[ncnt].fr=i+n,q[ncnt].tt=j,q[ncnt].ff=a[i][j];
				}
			}
		}
		for(int i=1;i<=ncnt;i++)
		{
			d[i]=q[i];
		}
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		sort(d+1,d+1+ncnt,cmp);
		//cout<<ans<<" ";
		//cout<<ncnt;
		for(int i=1;i<=ncnt;i++)
		{
			b k=d[i];
			//cout<<" "<<k.fr<<" "<<k.tt<<" "<<k.ff<<"\n";
			if(Find(k.fr)==Find(k.tt))
			{
				continue;
			}
			ans+=k.ff;
			fa[Find(k.tt)]=Find(k.fr);
		}
		//cout<<ans<<"\n";
		ans2=min(ans,ans2);
		return;
	}
	p[x]=1;
	dfs(x+1,sum+c[x]);
	p[x]=0;
	dfs(x+1,sum);
	return;
}
void solve2()
{
	dfs(1,0);
	cout<<ans2;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		q[i].fr=u,q[i].tt=v,q[i].ff=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		sumc+=c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cnt=m;
	if(sumc==0)
	{
		solve1();
	}
	else
	{
		solve2();
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
0 1 0 2 4
*/
