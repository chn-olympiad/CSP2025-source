//GZ-S00341 贵阳市第三实验中学 王轶璋 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,tot=0,cost[N];
bitset<N> vis;
struct Node
{
	int to,w;
};
vector<Node> g[N],h[N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	tot=n+k;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		ans+=w;
	}
	cout<<ans<endl;
	for(int i=m+1;i<=tot;i++)
	{
		cin>>cost[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			h[i].push_back({j,w});
			h[j].push_back({i,w});
		}
	}
	return 0;
}
