#include<bits/stdc++.h>
using namespace std;

struct road
{
	long long u,v,w;
};
long long n,m,k,x,y,f[10011],s,l;
road r[1100001];

int fa(int z)
{
	if(f[z]==z)
	{
		return z;
	}
	f[z]=fa(f[z]);
	return f[z];
}

bool cmp(road o,road p)
{
	return o.w<p.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=0;i<1100001;i++)
	{
		r[i].u=r[i].v=r[i].w=INT_MAX;
	}
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<10011;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&y);
			r[m+i*n+j].u=n+i+1;
			r[m+i*n+j].v=j;
			r[m+i*n+j].w=y+x;
		}
	}
	m=m+n*k;
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int o=fa(r[i].u),p=fa(r[i].v);
		if(o!=p)
		{
			f[o]=p;
			s=s+r[i].w;
			l++;
			if(l==n+k-1)
			{
				break;
			}
		}
	}
	printf("%d",s);
	return 0;
}
