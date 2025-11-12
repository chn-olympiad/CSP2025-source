#include<bits/stdc++.h>
#define N 1005000
using namespace std;
long long n,m,k,fa[10050],sum;
long long ans;
long long c[15][10010],v[15];
struct node{
	long long val;
	long long l;
	long long r;
}a[N];
bool cmp(node x1,node x2)
{
	return x1.val<x2.val;
}
bool cmp_(long long x1,long long x2)
{
	return x1>x2;
}
long long find(long long x)
{
	return (fa[x]==x? x:fa[x]=find(fa[x]));
}
void solve()
{
	for(long long i=1;i<=m;i++)
	{
	  long long r=find(a[i].l),_r=find(a[i].r);
	  if(r!=_r)
		++sum,fa[r]=fa[_r],ans+=a[i].val;
	  else a[i].val=0x3f3f3f3f3f3f3f3f;
	}
}
long long get(long long ha)
{
	long long now=0,o=sum;
	node g[2001000];
	for(long long i=1;i<=sum;i++) g[i]=a[i];
	for(long long i=0;i<k;i++)
	  if(ha&(1<<i))
	    {
	      now+=c[i+1][0];
	      for(long long j=1;j<=n;j++)
	        g[++o].l=j,
			fa[10000+i+1]=10000+i+1,
			g[o].r=10000+i+1,
			g[o].val=c[i+1][j];
		}
	for(long long i=1;i<=n;i++) fa[i]=i;
	sort(g+1,g+1+o,cmp);
	for(long long i=1;i<=o;i++)
	{
	  long long r=find(g[i].l),_r=find(g[i].r);
	  if(r!=_r)
		fa[r]=fa[_r],
		now+=g[i].val;
	}
	return now;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)
	  fa[i]=i;
	for(long long i=1;i<=m;i++)
	  cin>>a[i].l>>a[i].r>>a[i].val;
	for(long long i=1;i<=k;i++)
	  for(long long j=0;j<=n;j++)
	    cin>>c[i][j];
	sort(a+1,a+1+m,cmp);
	solve();
	sort(a+1,a+1+m,cmp);
	for(long long i=1;i<(1<<k);i++)
	  ans=min(ans,get(i));
	cout<<ans;
}
