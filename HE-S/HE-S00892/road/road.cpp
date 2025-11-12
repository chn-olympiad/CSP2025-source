#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e4+5,M=1e6+5,K=15,inf=0x3f3f3f3f3f3f3f3f;
int n,m,k,pre[N],cur,c[K],a[K][N];
struct edge
{
	int l,r,val,nxt;
}e[M*2];
struct _
{
	int ix,d;
	bool friend operator<(_ x,_ y) {return x.d>y.d;}
};
set<int> vis;

/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

7 8 0
1 4 6
2 3 7
4 2 5
4 3 4
2 5 2
2 7 7
3 6 1
6 7 14
*/

void ae(int u,int v,int w) {e[++cur]={u,v,w,pre[u]},pre[u]=cur;}

bool afo=0;

void dfs16(int x)
{
	vis.insert(x);
	for(int i=pre[x];i;i=e[i].nxt)
	{
		if(e[i].val==-1)
		  continue;
		int r=e[i].r;
		if(vis.count(x))
		{
			afo=1;
			return ;
		}
		dfs16(r);
		if(afo)
		  return ;
	}
	vis.erase(x);
}

void k0_16pts()
{
	int ans=0;
	for(int i=1;i<=cur;i++)
	  ans+=e[i].val;
	for(int i=1;i<=n;i++)
	{
		dfs16(i);
		if(afo)
		{
			int maxn=0,il,ir;
			for(int j=1;j<=cur;j++)
			{
				int l=e[j].l,r=e[j].r;
				if(vis.count(l) && vis.count(r))
					if(e[j].val>maxn)
					  maxn=e[j].val,il=l,ir=r;
			}
			for(int j=pre[il];j;j=e[i].nxt)
				if(e[j].r==ir)
				{
					e[j].val=-1;
					ans-=e[j].val;
					break;
				}
			i--;
		}
	}
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++)
	  scanf("%lld%lld%lld",&u,&v,&w),ae(u,v,w),ae(v,u,w);
	bool isA=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0)
		  isA=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]!=0)
			  isA=0;
		}
	}
	if(k==0)
	{
		k0_16pts();
		return 0;
	}
	if(isA)
	  return !puts("0");
}
