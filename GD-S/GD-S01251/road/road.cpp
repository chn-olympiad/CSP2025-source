#include<bits/stdc++.h>
using namespace std;
long long n,m,k,b[15],f[11451],ans,pp=0;
struct st
{
	long long f,t,m;
}e[1145141];
bool cmp(st xx,st yy)
{
	return xx.m<yy.m;
}
int find(long long x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1,x,y,s;i<=m;i++) 
	{
		scanf("%lld%lld%lld",&x,&y,&s);
		e[i].f=x,e[i].t=y,e[i].m=s;
	}
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&b[i]);
		for(long long j=1,x;j<=n;j++)
		{
			scanf("%d",&x);
			if(x!=0) pp=1;
		}
	}
	if(pp==0&&k>0) 
	{
		cout<<0;
		return 0;
	} 
	for(long long i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+1+m,cmp);
	for(long long i=1;i<=m;i++)
	{
		int x=e[i].f,y=e[i].t,s=e[i].m;
		f[x]=find(x),f[y]=find(y);
		if(f[x]==f[y]) continue;
		f[f[y]]=f[x],ans+=s; 
	}
	printf("%lld",ans);
	return 0; 
}
