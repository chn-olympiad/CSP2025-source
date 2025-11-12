#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long c[15],a[15][10004];
struct Edge
{
	int u,v;
	long long w;
}e[1000006];
int cnt=0,b[10004][10004];
int ent=0,ans=0,fa[10004],lar[10004];
int find(int a)
{
	if(fa[a]!=a)
	{
		fa[a]=find(fa[a]);
	}
	return fa[a];
}
void merge(int a,int b)
{
	if(lar[find(a)]<lar[find(b)]) swap(a,b);
	fa[find(b)]=find(a);
	lar[find(a)]+=lar[find(b)];
	return;
}
long long read()
{
	long long x=0;
	int b=1;
	char c=getchar();
	while(c<'0'||'9'<c)
	{
		if(c=='-') b=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*b;
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	n=read();
	m=read();
	k=read();
	//cout<<n<<m<<k; 
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cnt++;
		e[cnt].u=read();
		e[cnt].v=read();
		e[cnt].w=read();
		b[e[cnt].u][e[cnt].v]=cnt;
		b[e[cnt].v][e[cnt].u]=cnt;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int t=1;t<=k;t++)
			{
				if(b[i][j]) e[b[i][j]].w=min(e[b[i][j]].w,c[t]+a[t][i]+a[t][j]);
				else
				{
					cnt++;
					e[cnt].u=i;
					e[cnt].v=j;
					e[cnt].w=c[t]+a[t][i]+a[t][j];
					b[i][j]=cnt;
					b[j][i]=cnt;
				}
			}
		} 
	}
	sort(e+1,e+cnt+1,cmp);
	//for(int i=1;i<=cnt;i++) cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
	for(int i=1;i<=m;i++)
	{
		if(ent==n-1) break;
		if(find(e[i].u)==find(e[i].v)) continue;
		merge(e[i].u,e[i].v);
		ans+=e[i].w;
		ent++;
	}
	cout<<ans;
	return 0;
}
