#include<bits/stdc++.h>
using namespace std;
int fa[10015];
struct stu{
	int x,y,w;
}a[1000005],p1[15][10015],p2[1025][10015];
bool comp(stu a,stu b)
{
	return a.w<b.w;
}
int Find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
int c[15],w[15][10005],len[1025];
long long ans;
int n,k,m;
void fnd(int x)
{
	long long sum=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int fl=0;
	for(int i=1;i<=k;i++)
	{
		if((1<<(i-1))&x)
		{
			sum+=c[i];
			if(!fl)
			{
				fl=i;
			}
		}
	}
	int tp1=1,tp2=1,tot=0,id=x-(1<<(fl-1));
	while(tp1<n+1||tp2<len[id]+1)
	{
		if((tp2==len[id]+1||p1[fl][tp1].w<p2[id][tp2].w)&&tp1!=n+1)
		{
			int u=Find(p1[fl][tp1].x),v=Find(p1[fl][tp1].y);
			if(u!=v)
			{
				sum+=p1[fl][tp1].w;
				fa[u]=v;
				p2[x][++tot]=p1[fl][tp1];
			}
			tp1++;
		}
		else
		{
			int u=Find(p2[id][tp2].x),v=Find(p2[id][tp2].y);
			if(u!=v)
			{
				sum+=p2[id][tp2].w;
				fa[u]=v;
				p2[x][++tot]=p2[id][tp2];
			}
			tp2++;
		}
	}
	ans=min(ans,sum);
	len[x]=tot;
}
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
void write(long long x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		a[i].x=read();
		a[i].y=read();
		a[i].w=read();
	}
	sort(a+1,a+m+1,comp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int tot=0;
	for(int i=1;i<=m;i++)
	{
		if(Find(a[i].x)!=Find(a[i].y))
		{
			p2[0][++tot]=a[i];
			ans+=a[i].w;
			fa[Find(a[i].x)]=Find(a[i].y);
		}
		if(tot==n-1) break; 
	}
	len[0]=tot;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) 
		{
			w[i][j]=read();
			p1[i][j]={n+i,j,w[i][j]};
		}
		sort(p1[i]+1,p1[i]+n+1,comp);
	}
	for(int i=1;i<(1<<k);i++)
	{
		fnd(i);
	}
	write(ans);
	return 0;
}
