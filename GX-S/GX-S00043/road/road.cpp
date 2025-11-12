#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long 
using namespace std;
void read(ll &x)
{
	x=0;
	bool meg=0;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			meg=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	if(meg==1)
		x=-x;
	return ;
}
void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	if(x>=10) write(x/10),putchar(x%10+'0');
}
ll k,n,m,ans;
ll tot,head[10001];
ll bcj[10001],bcjl[10001],bcjf[10001];
struct edge
{
	ll f,t,next;
	ll w;
}e[4000001];
void add(int f,int t,int w)
{
	e[++tot].f=f;
	e[tot].t=t;
	e[tot].w=w;
	e[tot].next=head[f];
	head[f]=tot;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
long long find(int x)
{
	if(bcj[x]==x)
		return x;
	return bcj[x]=find(bcj[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	ll f,t,w;
	for(int i=1;i<=m;i++)
	{
		read(f);
		read(t);
		read(w);
		add(f,t,w);
	}
	for(int i=1;i<=n;i++)
		bcj[i]=i,bcjl[i]=1;
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=m&&bcjl[1]<n;i++)
	{
		int x=find(e[i].f),y=find(e[i].t);
		if(x!=y)
		{
			bcj[x]=bcj[y];
			bcjl[x]=bcjl[y]=bcjl[x]+bcjl[y];
			bcjf[x]=bcjf[y]=bcjf[x]+bcjf[y]+e[i].w;
		}
	}
	for(int i=1;i<=k;i++)
	{
		bool flagfv=0,flagfr=0;
		read(w);
		if(w==0)
			flagfv=1;
		for(int i=1;i<=n;i++)
		{
			read(t);
			if(t!=0)
				flagfr=1;
		}
		if(flagfr==0&&flagfv==1)
		{
			write(0);
			return 0;
		}
	}
	write(bcjf[1]);
	return 0;
}

