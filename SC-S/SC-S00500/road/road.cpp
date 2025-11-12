#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+7;
int n,m,k;
struct road{
	int u,v;
	long w;
};
struct ly{
	int l[];
	int p;
};
long c[15],mn=MAXN;
long e[10005],a[15][10005];
road r[1000005];
bool x[1000005];
ly co[1000005];
bool lt()
{
	int t=0;
	for(int i=1;i<=n;i++)
	{
		if(e[i]==0)
			return 0;
		for(int j=0;j<=co[i].p;j++)
		{
			if(e[i]>1||e[co[i].l[j]]>1)
				continue;
			else
				return 0;
		}
	}
	return 1;
}
void solve(int q,int tot)
{
	if(lt()==1)
	{
		if(tot<=mn)
			mn=tot;
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(x[i]==1)
			continue;
		else
		{
			x[i]=1;
			e[r[q].u]+=1;
			e[r[q].v]+=1;
			co[r[q].v].l[co[r[q].v].p]=r[q].u;
			co[r[q].u].l[co[r[q].u].p]=r[q].v;
			co[r[q].u].p++;
			co[r[q].v].p++;
			solve(q+1,tot+r[q].w);
			x[i]=0;
			e[r[q].u]=0;
			e[r[q].v]=0;
			co[r[q].v].l[co[r[q].v].p]=0;
			co[r[q].u].l[co[r[q].u].p]=0;
			co[r[q].u].p--;
			co[r[q].v].p--;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%ld",&r[i].u,&r[i].v,&r[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%ld",c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%ld",a[i][j]);
		}
	}
	solve(1,0);
	cout<<mn;
	return 0;
 } 