#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int fa[maxn];

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

vector< pair<int,int> >G[10005]; 

struct node{
	int u,v,w;
}a[maxn];

bool cmp(node a,node b)
{
	return a.w<b.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		fa[i]=i;
		G[a[i].u].push_back({a[i].v,i});
		G[a[i].v].push_back({a[i].u,i});
	}
	int c1,c2;
	for (int j=1;j<=k;j++)
	{
		cin>>c1;
		for (int i=1;i<=n;i++)
		{
			cin>>c2;
			for (auto z:G[i])
			{
				int k=z.first,p=z.second;
				if(k==j)
				a[p].w=c2;
			}
		}
	}
	int cnt=0;
	long long dis=0;
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=maxn;i++)
	{
		if(cnt==n-1) break;
		int x=find(a[i].u),y=find(a[i].v);
		if(x==y) continue;
		fa[x]=y;
		cnt++;
		dis+=a[i].w;
	}
	cout<<dis;
	return 0;
}
