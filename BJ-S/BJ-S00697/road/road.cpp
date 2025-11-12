#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,d[10][10005],dis[100005],ans,fa[100005],cnt,outp,flag;
struct _
{
	ll u,v,w;
}tmp;
priority_queue<_>q;
deque<_>mp[100005];
bool operator <(_ x,_ y)
{
	return x.w>y.w;
}
ll find(ll x)
{
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void merge(ll x,ll y)
{
	x = find(x),y = find(y);
	fa[x] = y;
}
ll _k()
{
	while(q.size())q.pop();
	for(int i = 1;i<=n+k;i++)
	{
		for(int j = 0;j<mp[i].size();j++)
		{
			q.push(mp[i][j]);
		}
	}
	ans = 0;
	for(ll i = 1;i<=n+k;i++)fa[i] = i;
	while(q.size())
	{
		tmp = q.top();
		q.pop();
		u = tmp.u,v = tmp.v,w = tmp.w;
		if(find(u)!=find(v))ans+=w,merge(u,v);
	}
	return ans;
}
ll _p()
{
	ans = 0;
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	for(ll j = 0;j<mp[1].size();j++)
	{
		dis[mp[1][j].v] = min(dis[mp[1][j].v],mp[1][j].w);
	}
	ll minn;
	for(ll i = 1;i<n+k;i++)
	{
		minn = 0x3f3f3f3f3f3f3f3f;
		for(ll j = 1;j<=n+k;j++)
		{
			if(dis[j]>0&&dis[j]<minn)minn = dis[j],v = j;
		}
		ans+=dis[v];dis[v] = 0;
		for(ll j = 0;j<mp[v].size();j++)
		{
			dis[mp[v][j].v] = min(dis[mp[v][j].v],mp[v][j].w);
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i = 1;i<=m;i++)
	{
		cin>>u>>v>>w;
		mp[u].push_back({u,v,w});
		mp[v].push_back({v,u,w});
	}
	flag =1;
	for(ll i = 1;i<=k;i++)
	{
		for(ll j = 0;j<=n;j++)
		{
			cin>>d[i][j];
		}
			if(d[i][0]>0)flag = 0;
	}
	if(flag)
	{
		for(ll j = 0;j<k;j++)
		{
			for(ll l = 1;l<=n;l++)
			{
				mp[l].push_back({l,j+n+1,d[j+1][l]});
				mp[j+n+1].push_back({j+n+1,l,d[j+1][l]});
			}
		}
		cout<<_p();
		return 0;
	}
	outp= 0x3f3f3f3f3f3f3f3f;
	for(ll i = 0;i<(1<<k);i++)
	{
		cnt = 0;
		for(ll j = 0;j<k;j++)
		{
			if(i&(1<<j))
			{
				for(ll l = 1;l<=n;l++)
				{
					mp[l].push_back({l,j+n+1,d[j+1][l]});
					mp[j+n+1].push_back({j+n+1,l,d[j+1][l]});
				}
				cnt+=d[j+1][0];
			}
		}
		if(n>1000)
		{
			outp = min(outp,_k()+cnt);
		}
		else
		{
			outp = min(outp,_p()+cnt);
		}
		for(ll j = 0;j<k;j++)
		{
			if(i&(1<<j))
			{
				for(ll l = 1;l<=n;l++)
				{
					mp[l].pop_back();
					mp[j+n+1].pop_back();
				}
			}
		}
	}
	cout<<outp;
}