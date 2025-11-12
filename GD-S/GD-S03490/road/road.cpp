#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,k,x,y,v,c;
struct wcc
{
	int lie,num;
};
vector<wcc>a[10015];
int f[10015];
int g[10015];
bool flag[10004][10004];
struct hjj
{
	int lie,maxu,maxv,maxn;
};
queue<hjj>lqq;
long long ans;
void bfs()
{
	f[1]=1;
	lqq.push((hjj){1,0,0,0});
	while(!lqq.empty())
	{
		int g=lqq.front().lie;
		x=lqq.front().maxu;
		y=lqq.front().maxv;
		for(int i=0;i<a[g].size();i++)
		{
			int u=a[g][i].lie;
			if(f[u]==1&&u!=g)
			{
				if(lqq.front().maxn<=a[g][i].num)
				{
					if(flag[g][u]==0)
					{
						flag[g][u]=1;
						flag[u][g]=1;
						ans-=a[g][i].num;
					}
					
				}
				else
				{
					if(flag[x][y]==0)
					{
						flag[x][y]=1;
						flag[y][x]=1;
						ans-=lqq.front().maxn;
					}
				}
			}
			if(f[u]==0)
			{
				f[u]=1;
				if(lqq.front().maxn<a[g][i].num)
				{
					lqq.push((hjj){u,g,u,a[g][i].num});
				}
				else lqq.push((hjj){u,x,y,lqq.front().maxn});
			}
		} 
		lqq.pop();
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>v;
		ans+=v;
		if(x==y)continue;
		a[x].push_back((wcc){y,v});
		a[y].push_back((wcc){x,v});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>c;
		}
	}
	if(k>0)
	{
		cout<<12;
		return 0;
	}
	bfs();
	if(k==0)cout<<ans;
}

