#include<bits/stdc++.h> 
using namespace std;
//typedef long long ll;
int ct[1000005][1000005],n,k,ans;//the graph
int fa[1000005];
int Find(int u)
{
	if(fa[u]==u)
	{
		return u;
	}
	fa[u]=Find(fa[u]);
	return fa[u];
}
void Union(int u,int v)
{
	int a=Find(u),b=Find(v);
	if(a!=b)
	{
		fa[v]=a;
	}
}
struct edge{
	int c;//cost
	int d;//down
	bool operator<(edge e)
	{
		return c<e.c;
	}
};
void krus()
{
	for(int i=0;i<n;++i)
	{
		vector<edge> vec;
		for(int j=0;j<n+k;++j)
		{
			vec.push_back({ct[i][j],j});
		}
		sort(vec.begin(),vec.end());
		int s=vec.size();
		for(int j=0;j<s;++j)
		{
			if(Find(vec[j].d)!=Find(i))
			{
				Union(i,vec[j].d);
				ans+=ct[i][vec[j].d];
				break;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	cin>>n>>m>>k;
	for(int i=0;i<n;++i)
	{
		fa[i]=i;
	}
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ct[u][v]=w;
		ct[v][u]=w;
	}
	int vg=n;
	for(int i=0;i<k;++i)
	{
		int cg;
		cin>>cg;
		for(int j=0;j<n;++j)
		{
			cin>>ct[vg][j];
			ct[vg][j]+=cg;
			ct[j][vg]=ct[vg][j];
		}
	}
	//n+=k;
	krus();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
