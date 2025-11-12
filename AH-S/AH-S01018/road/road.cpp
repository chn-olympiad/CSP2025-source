#include<bits/stdc++.h>

using namespace std;

const int N=1050,M=2000010;

int n,m,k;
int fa[N];
struct Node
{
	int u,v,w;
	bool operator <(const Node t)const
	{
		return w<t.w;
	}
};

int findfa(int x)
{
	return x==fa[x]?x:fa[x]=findfa(fa[x]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	vector<Node> a;
	for(int i=1;i<=m;i++)
	{
		int u,v,s;
		scanf("%d%d%d",&u,&v,&s);
		a.push_back((Node){u,v,s});
	}
	
	for(int i=1;i<N;i++)
	{
		fa[i]=i;
	}
	
	for(int i=1;i<=k;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++)
		{
			int b;
			scanf("%d",&b);
			if(b==0)fa[findfa(i+n)]=findfa(j);
			else a.push_back((Node){i+n,j,b});
		}
	}
	
	sort(a.begin(),a.end());
	
	int res=0;
	for(int i=0;i<a.size();i++)
	{
		int u=a[i].u,v=a[i].v;
		if(findfa(u)!=findfa(v))
		{
			fa[findfa(u)]=findfa(v);
			res+=a[i].w;
		}
	}
	cout<<res<<endl;
		
	return 0;
}
