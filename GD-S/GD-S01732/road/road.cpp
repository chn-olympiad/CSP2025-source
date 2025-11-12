#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e4+100,M=1050100,K=15;
int n,m,k,ak,fa[N],cnt,c[K],cs[K],last[K];
ll sum; 
struct node
{
	int u,v,w;
}a[M];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
bool cmp(node a1,node a2)
{
	return a1.w<a2.w;
}
int set_find(int x)
{
	return fa[x]==x?x:fa[x]=set_find(fa[x]);
}
void set_merge(int x,int y)
{
	int gx=set_find(x),gy=set_find(y);
	if(gx!=gy) fa[gx]=gy;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	while(m--)
	{
		ak++;
		a[ak].u=read(),a[ak].v=read(),a[ak].w=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		sum+=c[i];
		for(int j=1;j<=n;j++)
		{
			a[++ak].w=read();
			a[ak].u=n+i,a[ak].v=j;
		}
	} 
	sort(a+1,a+ak+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=ak;i++)
	{
		if(set_find(a[i].u)!=set_find(a[i].v)) 
		{
			if(a[i].u>n) cs[a[i].u-n]++,last[a[i].u-n]=a[i].w;
			set_merge(a[i].u,a[i].v);
			sum+=a[i].w;
			cnt++;
		}
		if(cnt==n+k-1) break;
	}
	for(int i=1;i<=k;i++)
	{
		if(cs[i]<2) sum-=last[i],sum-=c[i];
	}
	printf("%lld",sum);
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/
