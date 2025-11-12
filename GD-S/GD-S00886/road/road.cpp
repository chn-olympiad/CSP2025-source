#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],cv[15],cw,b[10005],id,id1,id2,da,da1,da2,tp,q[10005];
struct h
{
	long long u,v,w;
}a[1000005],e[200005],xe[200005];
bool cmpp(h x,h y)
{
	return x.w<y.w;
}
long long zf(long long x)
{
	if(b[x]==x)return x;
	return x=zf(b[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=n;i++)b[i]=i;
	sort(a+1,a+1+m,cmpp); 
	for(int i=1;i<=m;i++)
	{
		if(zf(b[a[i].u])!=zf(b[a[i].v]))
		{
			id++,e[id]=a[i];da+=a[i].w;
			b[zf(b[a[i].u])]=b[zf(b[a[i].v])];
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&cv[i]);c[i]=i;
		da1=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&cw);
			xe[i*n+j].u=i,xe[i*n+j].v=j,xe[i*n+j].w=cw;
			da1+=cw;
		}
		da=min(da,da1); 
		tp+=cv[i];
	}
	sort(xe+1,xe+1+k*n,cmpp);
	for(int j=0;j<(1<<k);j++)
	{
		id=0;id1=1,id2=1;da1=0;
		for(int i=j;i>0;i/=2) 
		{
			id++;
			q[id]=i%2;
			da1+=cv[id]*(i%2);
		}
		for(int i=1;i<=n;i++)b[i]=i;
		for(int i=1;i<=n-1;)
		{
			if(xe[id1].w<e[id2].w)
			{
				if(q[xe[id1].u]&&zf(b[xe[id1].u])!=zf(b[xe[id1].v]))
				{
					i++;
					da1+=xe[id1].w;
					b[zf(b[xe[id1].u])]=b[zf(b[xe[id1].v])];
				}
				id1++;
			}
			else
			{
				if(zf(b[e[id2].u])!=zf(b[e[id2].v]))
				{
					i++;
					da1+=e[id2].w;
					b[zf(b[e[id2].u])]=b[zf(b[e[id2].v])];
				}
				id2++;
			}
		}
		id=0;
		for(int i=j;i>0;i/=2) 
		{
			id++;
			q[c[id]]=0;
		}
		da=min(da1,da);
	}
	printf("%lld",da);
		
	
	return 0;
}
