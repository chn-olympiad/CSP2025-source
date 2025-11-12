#include<bits/stdc++.h>
using namespace std;
#define gyz cout<<"gyz"
typedef long long ll;
struct edge{
	int x,y,w,nxt;
}e[2700020];
int head[10005];
int cnt;
void in(int x,int y,int w)
{
	e[++cnt]={x,y,w,head[x]};
	head[x]=cnt;
}
int f[10500];
int ww[10005];
int find(int x)
{
	if(f[x]==x){
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
} 
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		in(a,b,c);
		in(b,a,c);
	}
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&ww[j]);
		}
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<=n;z++)
			{
				if(z!=j){
					in(z,j,c+ww[z]+ww[j]);
				}
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int sum=0,u,v;
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(sum==n+k-1)break;
		u=e[i].x;
		v=e[i].y;
		u=find(u);
		v=find(v);
		if(u==v)continue;
	//	cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].w<<endl;
		ans+=e[i].w;
		sum++;
		f[u]=v;
	}
	cout<<ans;
	
	return 0;
} 
