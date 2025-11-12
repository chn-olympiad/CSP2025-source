#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
const int N=10020;
vector<pair<int,int> > p[N];
int n,m,k;
int vis[N],dis[N];
int c[20];
set<pair<int,int> > q;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	fo(i,1,m)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		p[u].push_back({v,w});
		p[v].push_back({u,w});
	}
	fo(i,1,k)
	{
		scanf("%lld",&c[i]);
		fo(j,1,n)
		{
			int w;
			scanf("%lld",&w);
			p[n+i].push_back({j,w});
		}
	}
//	for(auto i:p[5])cout<<i.first<<" "<<i.second<<endl;
	int ans=LLONG_MAX;
	fo(t,0,(1<<k)-1)
	{
		fo(i,1,n+k)vis[i]=0,dis[i]=LLONG_MAX;
		int res=0;
		fo(i,1,k)	
			if(t&(1<<(i-1)))
			{
				res+=c[i];
				for(auto j:p[n+i])
					p[j.first].push_back({n+i,j.second});
			}
		dis[1]=0;
		vis[1]=1;
		for(auto i:p[1])
			q.insert({i.second,i.first}),
			dis[i.first]=i.second;
//		cout<<t<<" "<<res<<endl;
		while(!q.empty())
		{
			int x=(*q.begin()).second,y=(*q.begin()).first;
			q.erase(q.begin());
			if(vis[x])continue;
//			cout<<x<<" "<<dis[x]<<endl;
			vis[x]=1;
			res+=y;
			for(auto i:p[x])
				if(dis[i.first]>i.second&&!vis[i.first])
				{
					if(dis[i.first]!=LLONG_MAX)
						q.erase({dis[i.first],i.first});
					dis[i.first]=i.second;
					q.insert({i.second,i.first});
				}
		}

		ans=min(ans,res);
		fo(i,1,k)	
			if(t&(1<<(i-1)))
				fo(j,1,n)p[j].pop_back();
	}
	cout<<ans;
	return 0;
}
