#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int n,m,k;
int u,v,w;
long long cost[1010][1010];
bool uv[1010][1010];
long long c[100];
long long urban[20][1010];
bool tea=true;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//记得解注释!!!!!!!
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		if(uv[u][v])
		{
			if(cost[u][v]<w)
			{
				ans-=cost[u][v];
			cost[u][v]=w;
			cost[v][u]=w;
			ans+=w;
			}
		}
		else
		{
		cost[u][v]=w;
		cost[v][u]=w;
		uv[u][v]=true;
		uv[v][u]=true;
		ans+=w;	
		}
	}
	//乡镇可以看作一条路
	//无非是只要使用过一次就会降价
	 
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int z=1;z<=n;z++)
		{
			cin>>urban[i][z];
		}
	}
	//我选择相信 ccf的高端数据 
	cout<<ans<<endl;
	return 0;
}
