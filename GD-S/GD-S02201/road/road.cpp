#include<bits/stdc++.h>
using namespace std;
const int maxm=2e6+5,maxn=1e4+5;
int m,n,k,c[10][maxn],fa[maxn],sz[maxn],tot,cnt,p,mx;
long long ans;
bool check[maxm],vis;
struct edge{
	int u,v,w;
}e[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
void merge(int a,int b)
{
	a=find(a),b=find(b);
	if(sz[a]<sz[b]) swap(a,b);
	fa[b]=a;
	sz[a]+=sz[b];
}
void kruskal()
{
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(u>n&&check[u]==false)
		{
			check[u]=true;
			p++;
		 } 
		 if(v>n&&check[v]==false)
		{
			check[v]=true;
			p++;
		 } 
		if(find(u)!=find(v))
		{
			merge(u,v);
			ans+=w;
			tot++;
		}
		if(p>0)
		{
			if(tot==n+p-1)
		{
			cout<<ans;
			break;	
		}
		}
		else if(tot==n-1)
		{
			cout<<ans;
			break;	
		}
	}
	
}
void init()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i,sz[i]=1;
	}
	cnt=n;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		mx=max(e[i].w,mx);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i][0];
		if(c[i][0]<=mx)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>c[i][j];
				if (c[i][j]+c[i][0]<=mx)
				{
				cnt++;
				e[cnt].u=n+i,e[cnt].v=j,e[cnt].w=c[i][j];
				}
				else{
					vis=true;
				}
			}
			if(!vis)
			{
				cnt++;
				e[cnt].u=0,e[cnt].v=n+i,e[cnt].w=c[i][0];
			}
		}
		else
		{
			 for(int j=1;j<=n;j++)
			{
				cin>>c[i][j];
				cnt++;
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	kruskal();	
	
}
int main()
{  
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	return 0;
 } 
 /*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
3 3 0
1 2 1
2 3 2
3 1 3
 */
