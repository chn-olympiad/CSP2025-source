#include <bits/stdc++.h>
#define _F(x,y,z) for(int x=y;x<=z;x++)
#define F_(x,y,z) for(int x=y;x>=z;x--)
#define TF(x,y,z) for(int x=head[y],z,;x;x=nex[x])

using namespace std;

typedef long long ll;
typedef const int ci;
typedef double dou;
typedef pair<int,int> pii;

int read()
{
	int x=0,fl=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			fl*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
		x=x*10+c-'0',c=getchar();
	return x*fl;
}

ci maxn=2e6+10;
int n,m,tot,fa[maxn],ok[40];
ll res,ans=0x3f3f3f3f3f3f3f3f;
int k,a[15][maxn],c[maxn];
struct ss 
{
	int x,y,v,id;
}e[maxn],lst[maxn];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void kruskal1()
{
	res=0;
	_F(i,1,n)
		fa[i]=i;
	int cnt=0;
	_F(i,1,m)
	{
		int x=e[i].x,y=e[i].y,v=e[i].v;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			res+=v;
			cnt++;
			lst[cnt]=e[i];
		}
		if(cnt==n-1)
		{
			ans=min(ans,res);
			return ;
		}
	}
}
void kruskal2(int t)
{
	int nn=n;res=0;
	ok[0]=1;
	_F(i,1,k)
	{
		ok[i]=0;
		if(t&(1<<(i-1)))
		{
			nn++;
			ok[i]=1;
			res+=c[i];
		}
	}
	if(res>ans)
		return ;
	_F(i,1,n+k)
		fa[i]=i;
//			printf("%lld\n",res);
	int cnt=0;
	_F(i,1,tot)
	{
		int x=lst[i].x,y=lst[i].y,v=lst[i].v;
		if(!ok[lst[i].id]) continue;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			res+=v;
			cnt++;
		}
//			printf("%lld\n",res);
		if(cnt==nn-1)
		{
			ans=min(ans,res);
			return ;
		}
		if(res>ans)
			return ;
	}
}
void work()
{
//	scanf("%d%d%d",&n,&m,&k);
	n=read(),m=read(),k=read();
	_F(i,1,m)
	{
		int x,y,v;
//		scanf("%d%d%d",&x,&y,&v);
		x=read(),y=read(),v=read();
		e[i]={x,y,v,0};
	}
	_F(i,1,k)
	{
//		scanf("%d",&c[i]);
		c[i]=read();
		_F(j,1,n)
			a[i][j]=read();
//			scanf("%d",&a[i][j]);
	}
	sort(e+1,e+1+m,[](ss x,ss y){return x.v<y.v;});
	kruskal1();
	tot=n-1;
	_F(i,1,k)
	{
		_F(j,1,n)
			lst[++tot]={j,n+i,a[i][j],i};
	}
	sort(lst+1,lst+1+tot,[](ss x,ss y){return x.v<y.v;});
	_F(i,1,(1<<k)-1)
		kruskal2(i);
	printf("%lld",ans);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	int t;
//	scanf("%d",&t);
//	while(t--)
		work();
	fclose(stdin);
	fclose(stdout);
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
done? on 16:40
*/


