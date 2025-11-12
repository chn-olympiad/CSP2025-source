#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	int to;
};
struct node1{
	int now;
	int val;
	int to;
};
int n,m,k;
bool flag[10005];
int cnt=1;
int w=0;
vector<node > v[10005];
priority_queue<node1 >q;
void bfs()
{
	flag[1]=true;
	for(int i=0;i<v[1].size();i++)
	{
		node1 k;
		k.now=1;k.val=v[1][i].val;k.to=v[1][i].to;
		q.push(k);
	}
	while((cnt!=n)&&(!q.empty()))
	{
		while(!q.empty())
		{
			if(flag[q.top().to])q.pop();
		}
		node1 t=q.top();
		for(int i=0;i<v[t.now].size();i++)
		{
			if(!flag[v[t.now][i].to])
			{
				q.push({t.now,v[t.now][i].val,v[t.now][i].to});
			}
			flag[t.now]=true;
			cnt++;
			w+=t.val;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int k1,k2,k3;
		scanf("%d%d%d",&k1,&k2,&k3);
		v[k1].push_back({k2,k3});
		v[k2].push_back({k1,k3});
	}
	memset(flag,false,sizeof(flag));
	bfs();
	printf("%d\n",w);
}
