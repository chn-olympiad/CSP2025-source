#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int N=1e4+114,M=1e6+3e4;
int n,m,k,fa[N];
struct node
{
	int x,y,z;
}edge[M];
bool operator <(node x,node y){return x.z<y.z;}
int find(int x)
{
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
bool check()
{
	int x=find(1);
	for(int i=2;i<=n;i++)if(find(i)!=x)return 0;
	return 1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[i]={x,y,z};
	}
	for(int i=1;i<=k;i++)
	{
		int dx;cin>>dx;
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			edge[++m]={n+i,j,x};
		}
	}
	sort(edge+1,edge+1+m);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int ans=0,sum=0;
	for(int i=1;i<=m;i++)
	{
		int x=find(edge[i].x),y=find(edge[i].y);
		if(x==y)continue;
		fa[x]=y;
		ans+=edge[i].z;
		if(check())break;
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/