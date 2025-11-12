#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=0;
long long path[10100];
bool flag[10100],f[10100];
long long city[10100],sum,dis[10100];
struct tu
{
	int to;
	long long distance;
};
queue<tu>q[10100];
struct p
{
	int id;
	long long distance;
	bool operator <(const p &x)const
	{
		return x.distance<distance;
	}
};
priority_queue<p>primq;
void out()
{
	cout<<sum;
	exit(0);
}
void Prim()
{
	primq.push({1,0});
	dis[1]=0;
	while(!primq.empty())
	{
	//	cout<<endl;
		p t=primq.top();
	//	cout<<"pop "<<t.id<<" dis="<<dis[t.id]<<endl;
		primq.pop();
		if(flag[t.id]==1)
		{
	//		cout<<"continue"<<endl;
			continue;
		}
		int nowid=t.id; 
		sum+=dis[nowid];
//		cout<<"("<<t.distance<<")"<<nowid<<"->";
		if(nowid<=n)
		{
			cnt++;
			path[cnt]=dis[nowid]-path[cnt-1];
			if(cnt==n)
			{
				out();
			}
		}
		flag[nowid]=1;
		for(int i=1;i<=q[nowid].size();i++)
		{
			tu t=q[nowid].front();
			int to=t.to;
			long long distance=t.distance;
			long long totaldistance=distance+city[to];
			if(f[to]==1)
			{
				totaldistance-=city[to];
			}
			else
			{
				f[to]=1;
			}
			if(!flag[to]&&totaldistance<dis[to])
			{
	//			cout<<"add "<<to<<" from"<<dis[to]<<" to "<<distance+dis[nowid]+city[to]<<" into the queue"<<endl;
				dis[to]=totaldistance;
				primq.push({to,dis[to]-dis[nowid]});
			}
			q[nowid].push(q[nowid].front());
			q[nowid].pop();
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=(n+k)*2;i++)
	{
		city[i]=0;
		flag[i]=0;
		f[i]=0;
		dis[i]=INT_MAX;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,distance;
		cin>>x>>y>>distance;
		q[x].push({y,distance});
		q[y].push({x,distance});
	}
	for(int i=1;i<=k;i++)
	{
		int t;
		cin>>t;
		city[n+i]=t;
		for(int j=1;j<=n;j++)
		{
			int x,y;
			long long distance;
			cin>>distance;
			x=i+n;
			y=j;
			q[x].push({y,distance});
			q[y].push({x,distance});
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q[i].size();j++)
		{
			tu t=q[i].front();
			cout<<t.to<<" ";
			q[i].push(q[i].front());
			q[i].pop();
		}
		cout<<endl;
	}*/
	Prim();
	out();
}
