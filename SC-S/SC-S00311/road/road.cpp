#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5;
int n,m,k;
int a,b,c,fa[N],dis[N],mini,minn;
bool vis[N];
long long ans;
struct node
{
	int to,nex,w;
}g[2*M];
int h[N],cnt;
void add(int x,int y,int z)
{
	g[++cnt].to=y;
	g[cnt].w=z;
	g[cnt].nex=h[x];
	h[x]=cnt;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		ans+=c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a;
		for(int j=1;j<=n;j++)
			cin>>b;
	}
	cout<<ans;	
	return 0;
}