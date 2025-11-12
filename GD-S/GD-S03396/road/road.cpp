#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
vector<int> vec[10005];
int fa[10005],use[15],tot[15];
ll c[15];
pair<ll,int> cost[15][10005];
struct node
{
	int u,v,w;
}edge[1000005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find_fa(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find_fa(fa[x]);
}
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	sort(edge+1,edge+m+1,cmp);
	priority_queue<pair<pair<ll,int>,pair<int,int>>,vector<pair<pair<ll,int>,pair<int,int>>>,greater<pair<pair<ll,int>,pair<int,int>>>> q;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>cost[i][j].first,cost[i][j].second=j;
		sort(cost[i]+1,cost[i]+n+1);
		q.push({{c[i]+cost[i][1].first+cost[i][2].first,i},{1,2}});
	}
	int num=n;
	ll ans=0;
	for(int i=1;i<=m;)
	{
		if(num==1) break;
		int x=edge[i].u,y=edge[i].v;
		ll len=edge[i].w;
		x=find_fa(x),y=find_fa(y);
		if(x==y)
		{
			i++;
			continue;
		}
		else
		{
			ll now=0;
			int x1=-1,y1=-1,pos=-1;
			while(!q.empty())
			{
				auto p=q.top();
				ll opt=p.first.first;
				int id=p.first.second;
				int p1=p.second.first,p2=p.second.second;
				if(opt>len) break;
				if(tot[pos]>n)
				{
					q.pop();
					continue;
				}
				if(find_fa(cost[id][p1].second)==find_fa(cost[id][p2].second))
				{
					q.pop();
					tot[pos]++;
					if(p1==p2-1)
					{
						if(p2+1<=n)
						{
							ll hhh=c[id]+cost[id][p1].first+cost[id][p2+1].first;
							if(use[id]) hhh-=c[id];
							q.push({{hhh,id},{p1,p2+1}});
						}
					}
					else
					{
						ll now1=c[id]+cost[id][p1+1].first+cost[id][p2].first;
						if(use[id]) now1-=c[id];
						ll now2=inf;
						if(p2+1<=n)
						{
							now2=c[id]+cost[id][p1].first+cost[id][p2+1].first;
							if(use[id]) now2-=c[id];
						}
						q.push({{now1,id},{p1+1,p2}});
						if(now2!=inf) q.push({{now2,id},{p1,p2+1}});
					}
				}
				else
				{
					pos=id,now=opt,x1=cost[id][p1].second,y1=cost[id][p2].second;
					break;
				}
			}
			if(x1==-1)
			{
				ans+=len;
				fa[y]=x;
				i++;
			}
			else
			{
				if(now<len) ans+=now,fa[find_fa(y1)]=find_fa(x1),use[pos]=1,tot[pos]++;
				else ans+=len,fa[y]=x,i++;
			}
			num--;
		}
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

