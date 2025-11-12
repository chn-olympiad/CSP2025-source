#include<bits/stdc++.h>
#define ll long long
#define up(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+10;
ll n,m,k,fa[N],f[N],c[N],a[10010][13],ss[13],xx,fy[N<<1],cnt,n2,ans;
struct edge
{
	ll u,v,w,id;
}e[N<<1];
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	freopen("road.in","r",stdin);	
	freopen("road.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	up(i,1,n+k)fa[i]=i;
	up(i,1,m)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,[](edge a,edge b){return a.w<b.w;});
	up(i,1,m)
	{
		ll x=e[i].u,y=e[i].v;
		x=find(x);y=find(y);
		if(x==y)continue;
		if(x<y)swap(x,y);
		fa[y]=x;
		ans+=e[i].w;
		fy[++cnt]=e[i].w;
		if(cnt==n-1)break;
	}
	up(i,1,n+k)fa[i]=i;
	cnt=ans=0;
	up(i,1,k)
	{
		cin>>c[i];
		up(j,1,n)
		{
			int x;
			cin>>x;
			e[++m]={n+i,j,x+c[i],i};
		}
		f[i]=-1;
	}
	sort(e+1,e+m+1,[](edge a,edge b){return a.w<b.w;});
	up(i,1,m)if(e[i].id)a[e[i].id][++ss[e[i].id]]=i;
	n2=0;
	up(i,1,m)
	{
		ll x=e[i].u,y=e[i].v;
		x=find(x);y=find(y);
		if(x==y)continue;
		if(x<y)swap(x,y);
		if(x>n&&f[x-n]==-1)
		{
			fa[y]=x;
			x-=n;
			f[x]=i;
			up(j,1,n)	e[a[x][j]].w-=c[x];
			sort(e+i+2,e+m+1,[](edge a,edge b){return a.w<b.w;});
		}
		else
		if(x>n)
		{
			x-=n;
			if(e[i].w+e[f[x]].w+c[x]>fy[cnt+1])
			{
				xx=i;	
				continue; 
			}
			n2++;
			ans+=e[i].w+e[f[x]].w+c[x];
			c[x]=0;
			f[x]=0;
			fa[y]=x+n;
			++cnt;
			xx=0;
		}
		else 
		{
			
			ans+=e[i].w,++cnt,fa[y]=x;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
} 
/*
最小生成树kruskal
暴力连边乡&城 
排序后
遇到乡边连接并减少其他同一乡边的费用 
*/
