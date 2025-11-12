#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
struct Ll{
	int to;
	long long w;
};
long long n,m,k,sg[11][10001],dis[10001],vis[10001],ans;
vector<Ll> h[10001];
priority_queue<Ll,vector<Ll>,greater<Ll> > q;
bool operator>(Ll a,Ll b)
{
	return a.w>b.w;
}
void djstla(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9,vis[i]=0;
	}
	dis[s]=0,vis[s]=1,ans=0;
	Ll a;
	a.to=s,a.w=0;
	q.push(a);
	while(!q.empty())
	{
		Ll t=q.top();
		q.pop();
		for(int i=0;i<h[t.to].size();i++)
		{
			if(!vis[h[t.to][i].to]&&dis[h[t.to][i].to]>dis[t.to]+h[t.to][i].w)
			{
				dis[h[t.to][i].to]=dis[t.to]+h[t.to][i].w;
				Ll r;
				r.to=h[t.to][i].to;
				r.w=dis[h[t.to][i].to];
				vis[r.to]=1;
				q.push(r);
					ans+=h[t.to][i].w;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie();
	cout.tie();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,s;
		cin>>u>>v>>s;
		Ll a,b;
		a.to=v,a.w=s,b.to=u,b.w=s;
		h[u].push_back(a);
		h[v].push_back(b);
	}
	bool b=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>sg[i][j];
			if(sg[i][j]!=0)
			{
				b=1; 
			}
		}
	}
	if(!b)
	{
		cout<<0;
		return 0;
	}
//	for(int u=1;u<=n;u++)
//	{
//		for(int j=1;j<=k;j++)
//		{
//			for(int v=1;v<=n;v++)
//			{
//				if(u!=v)
//				{
//					Ll a,b;
//					a.to=v,a.w=sg[j][0]+sg[j][u]+sg[j][v];
//					b.to=u,b.w=sg[j][0]+sg[j][u]+sg[j][v];
//					h[u].push_back(a);
//					h[v].push_back(b);
//				}
//			}
//		}
//	}
	
	djstla(1);
	cout<<ans;
	return 0;
}
