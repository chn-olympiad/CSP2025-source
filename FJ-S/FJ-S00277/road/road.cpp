#include<stdio.h>
#include<algorithm>
typedef long long ll;
int qread(void)
{
	int sign=1,num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	return sign*num;
}
struct edge
{
	int from,to,w;
}e[2000010];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int Set[20010],c[20],out[20],a[20][10010];
int Find(int x)
{
	if(Set[x]==x)
		return x;
	return Set[x]=Find(Set[x]);
} 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=qread(),m=qread(),k=qread();
//	fprintf(stderr,"%d %d %d\n",n,m,k);
	for(int i=1;i<=m;i++)
		e[i].from=qread(),e[i].to=qread(),e[i].w=qread();
	for(int i=1;i<=n;i++)
		Set[i]=i;
	if(k==0)
	{
		std::sort(e+1,e+1+m,cmp);
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
			int x=Find(e[i].from),y=Find(e[i].to);
			if(x!=y)
			{
				ans+=1ll*e[i].w;
				Set[x]=y;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
		c[i]=qread();
		if(c[i]!=0)
			flag=0;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=qread();
			if(!a[i][j])
				out[i]=j;
		}
		if(!out[i])
			flag=0;
	}
	if(flag)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				if(j!=out[i])
				{
					e[++m]={out[i],j,a[i][j]};
				}
		std::sort(e+1,e+1+m,cmp);
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
//			fprintf(stderr,"%d\n",i);
			int x=Find(e[i].from),y=Find(e[i].to);
			if(x!=y)
			{
				ans+=1ll*e[i].w;
				Set[x]=y;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			e[++m]={n+i,j,a[i][j]};
//	fprintf(stderr,"%d\n",m);
	std::sort(e+1,e+1+m,cmp);
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		for(int j=1;j<=n+k;j++)
			Set[j]=j;
		ll sum=0;
		for(int j=1;j<=m;j++)
		{
			if(e[j].from>n&&!(i&(1<<e[j].from-n-1)))
				continue;
			if(e[j].to>n&&!(i&(1<<e[j].to-n-1)))
				continue;
			int x=Find(e[j].from),y=Find(e[j].to);
			if(x!=y)
			{
				sum+=1ll*e[j].w;
				Set[x]=y;
			}
		}
		for(int j=1;j<=k;j++)
			if(i&(1<<j-1))
				sum+=1ll*c[j];
		if(sum<ans)
			ans=sum;
	}
	printf("%lld",ans);
	return 0;
}
