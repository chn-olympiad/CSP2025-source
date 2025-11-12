#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[20],col[10015],cb,cnt;
struct s1
{
	long long u,v,w;
	bool operator <(const s1 &p)const
	{
		return w>p.w;
	}
};
struct s2
{
	long long w,i;
	bool operator <(const s2 &p)const
	{
		return w>p.w;
	}
};
priority_queue<s1>q;
priority_queue<s2>cq[20];
vector<long long>adj[10015];
void bfs(int s,int clr)
{
	queue<int>bq;
	bq.push(s),col[s]=clr;
	while(!bq.empty())
	{
		int u=bq.front();
		bq.pop();
		for(int v:adj[u])
		{
			if(col[v]!=clr)
			{
				bq.push(v);
				col[v]=clr;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)col[i]=i;
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		q.push({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1,w;j<=n;j++)
		{
			scanf("%lld",&w);
			cq[i].push({w,j});
		}
	}
	while(cb<n-1)
	{
		while(col[q.top().u]==col[q.top().v])
		{
			q.pop();
		}
		long long minw=q.top().w,minu=q.top().u,minv=q.top().v,minnv=0;
		for(int i=1;i<=k;i++)
		{
			if(col[n+i])
			{
				while(col[cq[i].top().i]==col[n+i])
				{
					cq[i].pop();
				}
				if(cq[i].top().w<minw)
				{
					minw=cq[i].top().w;
					minu=cq[i].top().i;
					minv=n+i;
				}
			}
			else
			{
				long long u=cq[i].top().i,w=cq[i].top().w;
				cq[i].pop();
				while(col[cq[i].top().i]==col[u])
				{
					cq[i].pop();
				}
				if(cq[i].top().w+w+c[i]<=minw)
				{
					minw=cq[i].top().w+w+c[i];
					minu=u;
					minv=n+i;
					minnv=cq[i].top().i;
				}
				cq[i].push({w,u});
			}
		}
		cnt+=minw;
		adj[minu].push_back({minv});
		adj[minv].push_back({minu});
		if(minnv)
		{
			adj[minv].push_back({minnv});
			adj[minnv].push_back({minv});
		}
		bfs(minv,col[minu]);
		cb++;
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
