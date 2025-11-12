#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6;
long long read()
{
	long long res=0;
	char x=getchar();
	while(!('0'<=x&&x<='9'))
		x=getchar();
	while('0'<=x&&x<='9')
		res=(res<<3)+(res<<1)+x-'0',x=getchar();
	return res;
}
int fa[maxn<<1];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
long long n,m,k;
long long w,c[100];
struct Node{long long x,y,v;} s[maxn<<1];
int cnt,ss;
long long solve(int xx)
{
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	int ff=0;
	long long res=0;
	for(int i=1;i<=cnt;i++)
	{
		if((s[i].x>n&&(((xx>>(s[i].x-n-1))&1)==0))||(s[i].y>n&&(((xx>>(s[i].y-n-1))&1)==0)))
			continue;
		int sx=find(s[i].x),sy=find(s[i].y);
		if(sx!=sy)
		{
			fa[sx]=sy;
			res+=s[i].v;
			ff++;
			if(ff==ss-1)break;
		}
	}
	return res;
}
long long ans=1e18;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++)
	{
		cnt++;
		s[i].x=read();s[i].y=read();s[i].v=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			w=read();
			s[++cnt]={i+n,j,w};
		}
	}
	sort(s+1,s+cnt+1,[](Node a,Node b){return a.v<b.v;});
	for(int i=0;i<=(1<<k)-1;i++)
	{
		long long res=0;ss=n;
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1)res+=c[j],ss++;
		ans=min(ans,solve(i)+res);
	}
	printf("%lld",ans);
	return 0;
}
