#include<bits/stdc++.h>
using namespace std;
#define p pair<int,int>
#define f first
#define s second
int n,m,t,fly_dance,tot=0,kfc[10005],cango=1,sum=0;//  AK*FJ*OI/KJI=AFO
struct node
{
	int from;
	int to;
	int cost;
	int num;
}r[202000005];
vector<node> v[10005];
bool go[10005];
priority_queue<p,vector<p>,greater<p> > qp;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		node d,e;
		d.from=e.to=a;
		d.to=e.from=b;
		d.cost=e.cost=c;
		d.num=++tot;
		e.num=++tot;
		v[a].push_back(d);
		v[b].push_back(e);
		r[d.num]=d;
		r[e.num]=e;
	}
	for(int i=1;i<=t;i++)
	{
		cin>>fly_dance;
		for(int j=1;j<=n;j++)cin>>kfc[j];
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j!=k)
				{
					node a;
					a.from=j;
					a.to=k;
					a.cost=kfc[j]+kfc[k];
					a.num=++tot;
					v[j].push_back(a);
					r[a.num]=a;
				}
			}
		}
	}
	go[1]=1;
	for(int i=0;i<v[1].size();i++)qp.push(make_pair(v[1][i].cost,v[1][i].num));
	while(cango<n)
	{
		p t=qp.top();
		qp.pop();
		int fr=r[t.s].from,too=r[t.s].to;
		if(go[fr]&&go[too])continue;
		go[too]=1;
		sum+=t.f;
		cango++;
		for(int i=0;i<v[too].size();i++)qp.push(make_pair(v[too][i].cost,v[too][i].num));
	}
	cout<<sum;
	return 0;
}