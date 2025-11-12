#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
int n,m,k,c[21],fa[N];
struct mmm
{
	int id,sum;
};
vector<mmm>a[N];
struct edge
{
	int idx,idy,sum;
};
vector<edge>p;
bool cmp(edge x,edge y){return x.sum<y.sum;}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool add(int x,int y)
{
	int fax=find(x),fay=find(y);
	if(fax==fay) return false;
	fa[fay]=fax;
	return true;
}
ll jty(int ss)
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
	p.clear();
	int nx=0;
	for(int i=1;i<=n+k;i++)
	{
		if(i>n&&(ss&(1<<(i-n-1)))==0) continue;
		nx++;
		for(int j=0;j<int(a[i].size());j++)
		{
			if(a[i][j].id>n&&(ss&(1<<(a[i][j].id-n-1)))==0) continue;
			p.push_back({i,a[i][j].id,a[i][j].sum});
		}
	}
	sort(p.begin(),p.end(),cmp);
	int ssum=0;
	ll ssum2=0;
	for(int i=0;i<(int)p.size();i++)
	{
		if(add(p[i].idx,p[i].idy))
		{
			ssum++;
			ssum2+=p[i].sum;
		}
		if(ssum>=nx-1) break;
	}
	return ssum2;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	bool flag=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]!=0) flag=1;
		bool flag1=1;
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			if(x==0) flag1=0;
			a[i+n].push_back({j,x});
			a[j].push_back({i+n,x});
		}
		flag|=flag1;
	}
	if(k==0)
	{
		printf("%lld",jty(0));
		return 0;
	}
	if(flag==0)
	{
		printf("%lld",jty((1<<k)-1));
		return 0;
	}
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		ll sum=0;
		for(int j=0;j<k;j++)
		{
			if(i&(1<<j)) sum+=c[j+1];
		}
		ans=min(ans,jty(i)+sum);
	}
	printf("%lld",ans);
	return 0;
}
