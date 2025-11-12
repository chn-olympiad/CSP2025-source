#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e17;
const int N=1e4+100,M=1e6+7,K=15;
int read()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*y;
}
int n,m,k;
int fa[N];
ll c[K];
struct side
{
	int x,y;ll w;
}aaa[M],bbb[K][N];
bool cmp(side x,side y){return x.w<y.w;}
int getf(int x){return x==fa[x]?x:(fa[x]=getf(fa[x]));}
bool same(int x,int y){return getf(x)==getf(y);}
void merge(int x,int y){fa[getf(y)]=getf(x);}
int zy,zg[K],num;
bool cn[K];
ll work(ll rtn)
{
	for(int t=1;t<=n+num-1;t++)
	{
		ll ad=inf;int nxt=0;
		for(;zy<=m&&same(aaa[zy].x,aaa[zy].y);zy++);
		if(zy<=m)ad=aaa[zy].w;
		for(int i=1;i<=k;i++)
			if(cn[i])
			{
				for(;zg[i]<=n&&same(bbb[i][zg[i]].x,bbb[i][zg[i]].y);zg[i]++);
				if(zg[i]<=n)
				{
					if(ad>bbb[i][zg[i]].w)
						ad=bbb[i][zg[i]].w,nxt=i;
				}
			}
		if(nxt==0)rtn+=aaa[zy].w,merge(aaa[zy].x,aaa[zy].y),zy++;
		else rtn+=bbb[nxt][zg[nxt]].w,merge(bbb[nxt][zg[nxt]].x,bbb[nxt][zg[nxt]].y),zg[nxt]++;
	}
	return rtn;
}
ll ans=inf;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		aaa[i].x=read(),aaa[i].y=read(),aaa[i].w=read();
	sort(aaa+1,aaa+1+m,cmp);
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
			bbb[i][j].w=read(),bbb[i][j].x=i+n,bbb[i][j].y=j;
		sort(bbb[i]+1,bbb[i]+1+n,cmp);
	}
	for(int t=0;t<=(1<<k)-1;t++)
	{
		zy=1,num=0;ll chu=0;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=k;i++)zg[i]=1,cn[i]=0;
		for(int i=1,j=1;i<=t;i<<=1,j++)
			if(t&i)num++,cn[j]=1,chu+=c[j];
		ans=min(ans,work(chu));
	}
	printf("%lld",ans);
	return 0;
}