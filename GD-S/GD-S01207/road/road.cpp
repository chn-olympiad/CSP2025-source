#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct line
{
	int arr,r;
	int ned;//0不用,1自己要,2 arr要 
	line(){}
	line(int _arr,int _r,int _ned)
	{
		arr=_arr;
		r=_r;
		ned=_ned;
	}
};
struct node
{
	int id,cety;
	long long d;
	node(){}
	node(int _id,long long _d,int _cety)
	{
		id=_id;
		d=_d;
		cety=_cety;
	}
	bool operator<(const node c1)
	const{
		return c1.d<d;
	}
};
int n,m,k,c[11];
long long dis[10001][1025],ans[1025];
vector<line> g[10001];
priority_queue<node> q;
bool vis[10001][1025];
void prim ()
{
	memset(dis,0x3f3f,sizeof dis);
	dis[1][0]=0;
	q.push(node(1,0,0));
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		if(vis[now.id][now.cety]) continue;
		vis[now.id][now.cety]=1;
		ans[now.cety]+=now.d;
		for(int j=0;j<g[now.id].size();j++)
		{
			line i=g[now.id][j];
			if(i.ned==0)
			{
				if(dis[i.arr][now.cety]>(ll)i.r)
				{
					dis[i.arr][now.cety]=(ll)i.r;
					q.push(node(i.arr,dis[i.arr][now.cety],now.cety));
//					ans[now.cety]+=(ll)i.r;
				}
			}
			else if(i.ned==1)
			{
				if(now.cety&(1<<(now.id-1)))
				{
					if(dis[i.arr][now.cety]>(ll)i.r)
				    {
					    dis[i.arr][now.cety]=(ll)i.r;
					    q.push(node(i.arr,dis[i.arr][now.cety],now.cety));
//					    ans[now.cety]+=(ll)i.r;
				    }
				}
				else
				{
					if(dis[i.arr][now.cety|(1<<(now.id-1))]>(ll)i.r)
					{
						dis[i.arr][now.cety|(1<<(now.id-1))]=(ll)i.r+(ll)c[now.id];
						vis[now.id][now.cety|(1<<(now.id-1))]=1;
						q.push(node(i.arr,dis[i.arr][now.cety|(1<<(now.id-1))],(now.cety|(1<<(now.id-1)))));
//						ans[now.cety|(1<<(now.id-1))]+=(ll)i.r+(ll)c[now.id];
					}
				}
			}
			else
			{
				if(now.cety&(1<<(i.arr-1)))
				{
					if(dis[i.arr][now.cety]>(ll)i.r)
				    {
					    dis[i.arr][now.cety]=(ll)i.r;
					    q.push(node(i.arr,dis[i.arr][now.cety],now.cety));
//					    ans[now.cety]+=(ll)i.r;
				    }
				}
				else
				{
					if(dis[i.arr][now.cety|(1<<(i.arr-1))]>(ll)i.r)
					{
						dis[i.arr][now.cety|(1<<(i.arr-1))]=(ll)i.r+(ll)c[i.arr];
						vis[now.id][now.cety|(1<<(i.arr-1))]=1;
						q.push(node(i.arr,dis[i.arr][now.cety|(1<<(i.arr-1))],(1<<(i.arr-1))));
//						ans[now.cety|(1<<(i.arr-1))]+=(ll)i.r+(ll)c[i.arr];					}
				}
			}
		}
	}
}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		g[x].push_back(line(y,z,0));
		g[y].push_back(line(x,z,0));
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			if(j!=i)
			{
			    g[i].push_back(line(j,x,1));
			    g[j].push_back(line(i,x,2));
		    }
		}
	}
	prim();
	long long finalans=LONG_LONG_MAX;
	for(int i=0;i<=(1<<k)-1;i++)
	{
		int kp=0,v=i;
		while(v>0)
		{
			kp++;
			ans[i]+=(ll)(c[kp]);
			v/=2;
		}		
		if(ans[i]<finalans) finalans=ans[i];
    }
	printf("%lld",finalans);
	return 0; 
}
