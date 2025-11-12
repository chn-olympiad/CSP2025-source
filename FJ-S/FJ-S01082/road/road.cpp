#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,zs,f[2010],zst,ht;
long long c[11],ans=-1,sum;
bool d[11];
struct aa
{
	int x,y;
	long long v;
}a[2000010];
bool cmp(aa qwe,aa ewq)
{
	return qwe.v<ewq.v;
}
int ss(int x)
{
	if (f[x]==x) return x;
	else return f[x]=ss(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].v);
	tot=m;
	for (int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;j++)
		{
			scanf("%lld",&a[++tot].v);
			a[tot].x=n+i;a[tot].y=j;
		}
	}
	sort(a+1,a+tot+1,cmp);
	for (int i=0;i<(1<<k);i++)
	{
		zs=n-1;sum=zst=ht=0;
		for (int j=0;j<k;j++)
		{
			if ((1<<j)&i) zs++,sum+=c[j+1],d[j+1]=0;
			else d[j+1]=1;
		}
		for (int j=1;j<=n+k;j++) f[j]=j;
		while (zst<zs)
		{
			if (a[++ht].x>n)
			if (d[a[ht].x-n]) continue;
			int fx=ss(f[a[ht].x]),fy=ss(f[a[ht].y]);
			if (fx==fy) continue;
			f[fx]=f[fy];
			sum+=a[ht].v;zst++;
			if (sum>=ans&&ans!=-1) break;
		}
		if (ans==-1||ans>sum) ans=sum;
	}
	printf("%lld",ans);
}
