#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=1e6+50000;
int n,m,k,tot;
long long sum;
int fa[N];
bool pd[N];
struct Edge
{
	int x;
	int y;
	int w;
}a[M];
bool operator<(const Edge &q,const Edge &p)
{
	return q.w<p.w;
}
int get(int x)
{
	if(fa[x]==x)
	return x;
	return fa[x]=get(fa[x]);
}
void marry(int x,int y)
{
	int q=get(x),p=get(y);
	if(q==p)return ;
	fa[q]=p;
}
void Add(int w)
{
	
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[++tot].x=w+n;
		a[tot].y=i;
		a[tot].w=x;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		
//		cout<<i<<endl;
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[++tot].x=x;
		a[tot].y=y;
		a[tot].w=z;
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		scanf("%d",&c);
		Add(i);
	}
	
	sort(a+1,a+1+tot);
	for(int i=1;i<=tot;i++)
	{
		int x=a[i].x;
		int y=a[i].y;
		int w=a[i].w;
		if(get(x)!=get(y))
		{
			sum+=w;
			marry(x,y);
		}
	}
	cout<<sum;
	return 0;
}