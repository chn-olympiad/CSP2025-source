#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int cnt,pr;
int c[20],di[20][maxn],ne[maxn*200];
int f[maxn];
struct edge{
	int u,v,w;
}e[maxn*201];
bool cmp(edge A,edge B)
{
	return A.w<B.w;
}
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k;
	long long ans=0;
	cin>>n>>m>>k;
	
	if(k==0)
	{for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
	  int u,v,w;
	  cin>>u>>v>>w;
	  e[i].u=u;e[i].v=v;e[i].w=w;
	}
	sort(e+1,e+m+1,cmp);
	int sum=0;
	for(int i=1;i<=m;i++)
	{
	  int fu=find(e[i].u),fv=find(e[i].v);
	  if(fu!=fv)
	{
		f[fu]=fv;
		sum++;ans+=e[i].w;
	}
	if(sum==n-1) break;
	}
	  cout<<ans<<endl;
	 } 
	else
	{
	  for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
	  int u,v,w;
	  cin>>u>>v>>w;
	  e[i].u=u;e[i].v=v;e[i].w=w;
	}
	cnt=m;
	for(int i=1;i<=k;i++)
	{
	  cin>>c[i];
	  for(int j=1;j<=n;j++)
	  	cin>>di[i][j]; 
	}
	sort(e+1,e+cnt+1,cmp);
	int sum=0;
	for(int i=1;i<=cnt;i++)
	{
	  int fu=find(e[i].u),fv=find(e[i].v);
	  if(fu!=fv)
	{
		f[fu]=fv;
		sum++;ans+=e[i].w;
		ne[++pr]=e[i].w;
	}
	if(sum==n-1) break;
	}
	for(int i=pr;i>=pr-k+1;i--) ans-=ne[pr];
	  cout<<ans<<endl;
	 } 
	 return 0;
}
