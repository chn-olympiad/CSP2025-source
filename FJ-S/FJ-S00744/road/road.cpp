#include<bits/stdc++.h>
using namespace std;
long long c[11],a[11][10005],ans=1e17;
int n,m,k,f[200005],len,d,flag,r[100005],pp=1,ff[11];
struct aaa
{
	long long w;
	int u,v;
}p[2000005];
struct ccc
{
	long long w;
	int u,v;
}s[2000005];
bool bbb(aaa x,aaa y)
{
	return x.w<y.w;
}
int find(int k)
{
	if(k==f[k]) return k;
	return f[k]=find(f[k]);
}
void scs()
{
	sort(p+1,p+1+d,bbb);
	for(int i=1;i<=n+k;i++) f[i]=i,r[i]=0;
	long long num=0;
	int y=0;
	for(int i=1;i<=d;i++)
	{
		int u=find(p[i].u),v=find(p[i].v);
		long long w=p[i].w;
		if(u!=v)
		{
			f[u]=v;
			if(!r[u])
			{
				r[u]=1;
				if(u<=n) y++;
			}
			if(!r[v])
			{
				r[v]=1;
				if(v<=n) y++;
			}
			num+=w;
			if(y==n) break;
		}
	}
	for(int i=n+1;i<=n+k;i++) num+=r[i]*c[i-n];
	if(num<ans) ans=num,flag=1;
	else flag=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&s[i].u,&s[i].v,&s[i].w);
	len=d=m;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0) pp=0;
		int oo=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0) oo=1;
		}
		if(!oo) pp=0;
	}
	if(pp==1)
	{
		for(int i=1;i<=m;i++)
		{
			p[i].u=s[i].u;
			p[i].v=s[i].v;
			p[i].w=s[i].w;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				p[++d].u=n+i;
				p[d].v=j;
				p[d].w=a[i][j];
			}
		}
		scs();
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		p[i].u=s[i].u;
		p[i].v=s[i].v;
		p[i].w=s[i].w;
	}
	scs();
	for(int q=1;q<=k;q++)
	{
		for(int i=1;i<=len;i++)
		{
			p[i].u=s[i].u;
			p[i].v=s[i].v;
			p[i].w=s[i].w;
		}
		for(int i=len+1;i<=len+n;i++)
		{
			p[i].u=n+q;
			p[i].v=i-len;
			p[i].w=a[q][i-len];
		}
		d=len+n;
		scs();
		if(flag)
		{
			for(int i=len+1;i<=len+n;i++)
			{
				s[i].u=n+q;
				s[i].v=i-len;
				s[i].w=a[q][i-len];
			}
			len+=n;
		}
	}
	printf("%lld",ans);
	return 0;
}
