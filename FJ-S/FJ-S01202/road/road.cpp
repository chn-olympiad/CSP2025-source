#include<bits/stdc++.h>
using namespace std;
int n,m,k,ed,ans;
struct node{
	int to,daijia;
};
vector<node> vc[10005];
int xiuz[15],vis[10005],gg[15][10005];
void add(int q,int p,int w)
{
	vc[q].push_back({p,w});
	vc[p].push_back({q,w});
}
int pan()
{
	int aa=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])aa++;
	}
	return aa;
}
int bfs()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,1});
	while(pq.size())
	{
		pair<int,int> w=pq.top();
		pq.pop();
		if(vis[w.second])continue;
		vis[w.second]=1;
		cout<<w.second<<" "<<w.first<<" "<<pan()<<"\n";
		if(pan()==0)
		{
			return w.first;
		}
		for(int i=0;i<vc[w.second].size();i++)
		{
			node oo=vc[w.second][i];
			pq.push({w.first+oo.daijia,oo.to});
			for(int i=1;i<=k;i++)
			{
				pq.push({w.first+gg[i][oo.to]+xiuz[i]+gg[i][w.second],oo.to});
				gg[i][oo.to]=xiuz[i]=gg[i][w.second]=0;
			}
		}
		
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b,s;
		cin>>a>>b>>s;
		add(a,b,s);
	}
	int ct=0;
	for(int i=1;i<=k;i++)
	{
		cin>>xiuz[i];
		for(int j=1;j<=n;j++)
		{
			cin>>gg[i][j];
		}
	}
	cout<<bfs();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

