#include<bits/stdc++.h>
using namespace std;
int n,m,k,v,u,w;
int fa[10005],w1[10005],c[15],vis[15];
long long sum=0;
struct edge
{
	int u,v,w,p;
	friend bool operator < (const edge &a,const edge &b)
	{
		return a.w>b.w;
	} 
};
priority_queue<edge>q;
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return x;
}
void kual()
{
	int step=0;
	vis[0]=1;
	while(q.size()&&step<=n)
	{
		edge a=q.top();
		int fx=find(a.u),fy=find(a.v);
		if(fx!=fy)
		{
			q.pop();
			fa[fx]=fy;
			sum+=a.w;
			step++;
		}
		if(!vis[a.p])
		{
			vis[a.p]=1;
			sum+=w1[a.p];
		} 
		if(step==n-1) break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge a;
		a.u=u,a.v=v,a.w=w,a.p=0;
		q.push(a);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w1[j];	
		}
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<=n;z++)
			{
				edge a;
				if(j!=z)
				{
					a.u=u,a.v=z,a.w=w1[z]+w1[j],a.p=i;
					q.push(a);
				}
			}
		}
	}
	kual();
	cout<<sum;
return 0;
} 
