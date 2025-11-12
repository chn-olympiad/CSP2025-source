#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e3;
int map[MAXN][MAXN];
int map_1[MAXN][MAXN];
int can_map_1[MAXN];
int city[MAXN];
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		map[u][v]=w;
		map[v][u]=w;
	}
	for(int i=0;i<k;i++)
	{
		cin>>can_map_1[i];
		for(int j=0;j<n;j++)
		{
			cin>>map_1[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		
	}
//	C 国政府可以选择修复第 3 条和第 4 条道路，
//	然后将第 1 个乡镇进行城市化改造，
//并建造它与第 1,3 座城市间的道路，总费用为
// 5 + 4 + 1 + 1 + 2 = 13。可以证明，不存
//在比 13 更小的费用能使原有的 4 座城市两两连通
//。
}
