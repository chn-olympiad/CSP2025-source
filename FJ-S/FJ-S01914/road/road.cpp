#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5,M=2e6+5;
int n,m,k,sumc;
int fa[N+15],c[11];
ll ans=1e18,sum;
struct node{int x,y; ll z;}edge[M],edg[3000000];
bool cmp(node a,node b){return a.z<b.z;}
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
int calc(int x)
{
	int res=0;
	while(x) res+=(x&1),x>>=1;
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&edge[i].x,&edge[i].y,&edge[i].z);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]),sumc+=c[i];
		for(int j=1;j<=n;j++) m++,scanf("%lld",&edge[m].z),edge[m].x=j,edge[m].y=n+i;
	}
	if(sumc)
	{
		for(int zt=0;zt<(1<<k);zt++)
		{
			int nn=calc(zt)+n,mm=m-k*n; sum=0;
			for(int i=1;i<=m;i++) edg[i]=edge[i];
			for(int i=0;i<k;i++)
			{
				if(zt&(1<<i))
				{
					for(int j=m+i*n+1;j<=m+(i+1)*n;j++) edg[++m]=edge[j];
				}
			}
			for(int i=1;i<=nn;i++) fa[i]=i;
			sort(edg+1,edg+1+mm,cmp);
			for(int i=1;i<=mm;i++)
			{
				int x=get(edg[i].x),y=get(edg[i].y); ll z=edg[i].z;
				if(x^y) fa[x]=y,sum+=z;
			}
			ans=min(ans,sum);
		}
		printf("%lld",ans);
		return 0;
	}
	ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=get(edge[i].x),y=get(edge[i].y); ll z=edge[i].z;
		if(x^y) fa[x]=y,ans+=z;
	}
	printf("%lld",ans);
	return 0;
}
