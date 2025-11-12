#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<iomanip>
#include<bitset>
#include<deque>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
#define ull unsigned long long
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>57 or c<48){if(c==45)f=-1;c=getchar();}
	while(c<58 and c>47)x=x*10+c-48,c=getchar();
	return x*f;
}
void output(ll x)
{
	if(x<0)putchar(45),x=-x;
	if(x<10){putchar(x+48);return;}
	output(x/10);
	putchar((x%10)+48);
}
const int M=1000207,N=10207;
int n,m,k,tot;
struct sch{int next,to,val;}a[M<<1];
struct seg{int u,v,w;}e[M<<1];
struct ghtr{int to;ll val;};
bool operator < (const ghtr &A,const ghtr &B){return A.val>B.val;}
priority_queue<ghtr>q;
int head[N],f[N];
int c[20];
bool v[N],clear[20],used[20];
ll dis[N];
void add(int u,int v,int w){a[++tot]=(sch){head[u],v,w};head[u]=tot;}
void work()
{
	memset(dis,63,sizeof dis);
	dis[1]=0ll;
	q.push((ghtr){1,0});
	while(!q.empty())
	{
		int k=q.top().to;
		q.pop();
		if(v[k])continue;
		v[k]=true;
		for(int i=head[k],to;i;i=a[i].next)
			if(dis[to=a[i].to]>a[i].val)
			{
				dis[to]=a[i].val;
				if(k>n)dis[to]=(ll)c[k-n]+a[i].val+dis[k];
				q.push((ghtr){to,dis[to]});
			}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=dis[i];
	output(ans);
}
bool cmp(const seg &A,const seg &B){return A.w<B.w;}
int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
void Work()
{
	ll Ans=0;
	for(int i=1;i<=m;i++)e[i]=(seg){read(),read(),read()};
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int r1=find(e[i].u),r2=find(e[i].v);
		if(r1!=r2)
		{
			f[r1]=r2;
			Ans+=e[i].w;
		}
	}
	output(Ans);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	Work();
	return 0;
	/*for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			int w=read();
			add(j,i+n,w);
			add(i+n,j,w);
		}
	}
	work();
	return 0;*/
}

