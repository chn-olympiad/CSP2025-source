//GZ-S00171 毕节七星关东辰实验学校 张碧昊 
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long ll;
struct node
{
	ll u;
	ll v;
	ll val;
}road[52345];
vector<ll>tree[12345];
ll n,m,k;
ll f[12346];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
ll find(ll x)
{
	if(f[x]=x)return x;
	else f[x]=find(f[x]);
	return f[x];
}
bool vis[9999][9999];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll ans=1;
	cin>>n>>m>>k;
	ll cnt=1;
	for(int j=1;j<=n;j++)
	{
			
			f[j]=j;
	}
	for(int i=1;i<=m;i++)
	{
		ll u,v,kq;
		
		cin>>u>>v>>kq;
		
		f[u]=v;
		f[v]=u;
		road[cnt].u=u;
		road[cnt].v=v;
		road[cnt].val=kq;
		cnt++;
		road[cnt].u=v;
		road[cnt].v=u;
		road[cnt].val=kq;
		
	}
	cnt++;
	ll qwq[19][12346];
	ll va[12345];
	for(int i=1;i<=k;i++)
	{
		cin>>va[i];
		for(int j=1;j<=n;j++)
		{
			cin>>qwq[i][j];
		
		}
		
		for(int x=1;x<=n;x++)
		{
			for(int y=x+1;y<=n;y++)
			{
				ll op=qwq[i][x]+qwq[i][y]+va[i];
				
				road[cnt].u=x;
				road[cnt].v=y;
				road[cnt].val=op;
				cnt++;
				road[cnt].u=y;
				road[cnt].v=x;
				road[cnt].val=op;
			
			}
		}
	}

	sort(road+1,road+cnt+1,cmp);

	ll qwq1=1;
	ll xx=1;
	while(qwq1!=n)
	{
		if(vis[road[xx].v][road[xx].u]==true)xx++;
		else
		{
			if(road[xx].v==find(road[xx].u))
			{
				xx++;
			}
			else
			{
				ans+=road[xx].val;
				qwq1++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

