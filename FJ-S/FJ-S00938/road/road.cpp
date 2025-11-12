#include<bits/stdc++.h>
using namespace std;
long long n,m,k,b[30010],h[2024],c[11];
struct w{
	long long x,y,z;
}g[1000100],v[30010];
vector<w>f[2024];
bool p[2024];
bool ww(w a,w b)
{
	return a.z<b.z;
}
long long qui(long long x)
{
	if(b[x]==x)
		return x;
	return b[x]=qui(b[x]);
}
main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++)
		scanf("%lld%lld%lld",&g[i].x,&g[i].y,&g[i].z);
	sort(g+1,g+m+1,ww);
	for(long long i=1;i<=n;i++)
		b[i]=i;
	for(long long i=1;i<=m;i++)
		if(qui(g[i].x)!=qui(g[i].y))
		{
			f[0].push_back(g[i]);
			h[0]+=g[i].z;
			b[qui(g[i].x)]=qui(g[i].y);
		}
	p[0]=true;
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(long long j=1;j<=n;j++)
		{
			long long x;
			scanf("%lld",&x);
			g[j].x=n+i;
			g[j].y=j;
			g[j].z=x;
		}	
		sort(g+1,g+n+1,ww);
		long long t=0,l=1,r=1,x;
		x=f[0].size();
		while(l<=n&&r<=x)
		{
			if(f[0][r-1].z<g[l].z)
				v[++t]=f[0][r-1],r++;
			else
				v[++t]=g[l],l++;
		}
		while(l<=n)
			v[++t]=g[l],l++;
		while(r<=x)
			v[++t]=f[0][r-1],r++;
		for(long long q=1;q<=n+k;q++)
			b[q]=q;
		for(long long q=1;q<=t;q++)
			if(qui(v[q].x)!=qui(v[q].y))
			{
				f[1ll<<(i-1)].push_back(v[q]);
				h[1ll<<(i-1)]+=v[q].z;
				b[qui(v[q].x)]=qui(v[q].y);
			}
		p[1ll<<(i-1)]=1;
	}

	for(long long i=0;i<(1<<k);i++)
	if(!p[i])
	{
		p[i]=true;
		long long t=0,l=1,r=1,o=(i&(-i)),oo,x,y;
		oo=i^o;
		x=f[o].size();
		y=f[oo].size();
		while(l<=y&&r<=x)
		{
			if(f[o][r-1].z<f[oo][l-1].z)
				v[++t]=f[o][r-1],r++;
			else
				v[++t]=f[oo][l-1],l++;
		}
		while(l<=y)
			v[++t]=f[oo][l-1],l++;
		while(r<=x)
			v[++t]=f[o][r-1],r++;
		for(long long q=1;q<=n+k;q++)
			b[q]=q;
		for(long long q=1;q<=t;q++)
			if(qui(v[q].x)!=qui(v[q].y))
			{
				f[i].push_back(v[q]);
				h[i]+=v[q].z;
				b[qui(v[q].x)]=qui(v[q].y);
			}
	}
	long long s=1000000000000000000;
	for(long long i=0;i<(1<<k);i++)
	{
		long long ss=h[i];
		for(long long j=1;j<=k;j++)
			if(i&(1ll<<(j-1)))
				ss=ss+c[j];
		s=min(s,ss);
	}
	printf("%lld\n",s);
	
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/
