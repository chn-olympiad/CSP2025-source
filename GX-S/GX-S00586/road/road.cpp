#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,m,k,cnt,head[100010],fa[100001];
struct nx
{
	int to,dis,from;
}a[5000100];
inline void add(int from,int to,int dis)
{
	a[++cnt]=(nx){to,dis,from};
}
bool cmp(nx a1,nx a2)
{
	return a1.dis<a2.dis;
}
int find(int x)
{
	if(x!=fa[x])  fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)
    {
    	fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
    	int x,y,z;
    	scanf("%d%d%d",&x,&y,&z);
    	add(x,y,z);
    	add(y,x,z);
    }
    for(int i=1;i<=k;i++)
    {
    	int c;
    	cin>>c;
    	for(int j=1;j<=n;j++)
    	{
    		scanf("%d",&c);
    		add(n+i,j,c);
    		add(j,n+i,c);
    	}
    }
    int ans=0;
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
    	int x=a[i].from,y=a[i].to;
    	if(find(x)!=find(y))
    	{
    		ans+=a[i].dis;
    		fa[find(y)]=fa[find(x)];
    	}
    }
    cout<<ans;
	return 0;
}