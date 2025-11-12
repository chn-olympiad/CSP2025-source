#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 100009
#define rep(i,l,r,k) for(int i=l;i<=r;i+=k)
const int inf=2e9+10;
int q,n,maxcost=0,cA=1,cB=1;
int s,t,a[N],b[N],c[N];
struct Edge
{
	int last,to,w,cost;
}e[N<<3];
int head[N+10],cntedge=1;
void addedge(int u,int v,int w,int cost)
{
	e[++cntedge]=(Edge){head[u],v,w,cost};
	head[u]=cntedge;
	e[++cntedge]=(Edge){head[v],u,0,-cost};
	head[v]=cntedge;
}
int maxflow=0;
void init()
{
	cA=cB=1;
	rep(i,1,n+5,1) head[i]=0;
	cntedge=1;
	maxcost=0;
	maxflow=0;
}
int dis[N+10],vis[N+10],now[N+10];
bool spfa()
{
	rep(i,1,n+5,1) dis[i]=-inf,vis[i]=0;
	dis[s]=0;
	now[s]=head[s];
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u],v=e[i].to;i;i=e[i].last,v=e[i].to)
		{
//			if(u==4) 
//			{
//				cout<<endl;
//				cout<<"----"<<v<<" "<<e[i].w<<" "<<dis[v]<<" "<<dis[u]+e[i].cost<<endl;
//			}
//			
			if(dis[v]<dis[u]+e[i].cost&&e[i].w!=0)
			{
//			cout<<u<<" "<<v<<endl;
				dis[v]=dis[u]+e[i].cost;
				now[v]=head[v];
				if(vis[v]==0) q.push(v),vis[v]=1;
			}
		}
	}
//	cout<<endl;
//	rep(i,1,n+5,1) cout<<dis[i]<<" "; cout<<endl;
//	cout<<dis[t]<<endl;
	return dis[t]!=-inf;
}
int dfs(int u,int sum)
{
	int k,flow=0;
	if(u==t) return sum;
	for(int i=now[u],v=e[i].to;i&&sum;i=e[i].last,v=e[i].to)
	{
		now[u]=i;
		if(dis[u]+e[i].cost==dis[v]&&e[i].w!=0&&vis[v]==0)
		{
			vis[v]=1;
			k=dfs(v,min(e[i].w,sum));
			sum-=k,flow+=k;
			e[i].w-=k,e[i^1].w+=k;
			maxcost+=e[i].cost*k;
		}
	}
	return flow;
}
void dinic()
{
	while(spfa()) 
	{
		maxflow+=dfs(s,inf);
//		rep(u,1,n+5,1)
//			for(int i=head[u],v=e[i].to;i;i=e[i].last,v=e[i].to)
//				cout<<u<<" "<<v<<" "<<e[i].w<<" "<<e[i].cost<<endl;
//			cout<<endl;
	}
}
struct node
{
	int a,b,c;
}aaa[N];
bool cmp(node a,node b)
{
	return a.c>b.c;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--)
	{
		cin>>n;
		init();
		s=n+1,t=n+5;
		addedge(s+1,t,n/2,0),addedge(s+2,t,n/2,0),addedge(s+3,t,n/2,0);
		rep(i,1,n,1)
		{
			addedge(s,i,1,0);
			rep(j,1,3,1)
			{
				int cost;
				cin>>cost;
				if(j==1) a[i]=cost;
				if(j==2) b[i]=cost;
				if(j==3) c[i]=cost;
				if(j==3&&cost!=0) cB=0;
				if(j==2&&cost!=0) cA=0;
				addedge(i,s+j,1,cost);
			}
		}
		if(n<=200)
		{
			dinic();
				cout<<maxcost<<endl;
				continue;
		}
		if(cB&&cA)
		{
			sort(a+1,a+1+n);
			int ans=0;
			for(int i=n;i>n/2;i--)
				ans+=a[i];
			cout<<ans<<endl;
		}
		else
		{
			if(cB)
			{
				int ans=0;
				rep(i,1,n,1)
				{
					aaa[i]=(node){a[i],b[i],abs(a[i]-b[i])};
				}
				int cnta=0,cntb=0;
				rep(i,1,n,1)
				{
					if(cnta==n/2) ans+=aaa[i].b;
					else
					{
						if(cntb==n/2) ans+=aaa[i].a;
						else
						{
							if(aaa[i].a>aaa[i].b) ans+=aaa[i].a,cnta++;
							else ans+=aaa[i].b,cntb++;
						}
					}
				}
				cout<<ans<<endl;
			}
			else
			{
				dinic();
				cout<<maxcost<<endl;
			}
		}
		
	}
	return 0;
}
