#include<bits/stdc++.h>

using namespace std;

int n,m,k,mincost = 1e9;

void dfs(int point,int isbuild,long long cost,int step,vector<bool> isgo,vector<vector<int> > city , vector<vector<int> > build , vector<int> gzf)
{
	isgo[point] = true;
	if(step == n)
	{
		isgo[point] = false;
		if(mincost > cost)
		{
			mincost = cost;
			return;
		}
	}
	for(int i = 1; i <= n;i ++)
	{
		if(point != i)
		{
			if(isgo[i] == false && isbuild < k)
			{
				dfs(i,isbuild+1,cost + build[isbuild+1][i] + gzf[isbuild+1] + build[isbuild+1][point],step+1,isgo,city,build,gzf);
				isgo[i] = false;
			}
			if(isgo[i] == false && city[point][i] != -1)
			{
				dfs(i,isbuild,cost + city[point][i],step+1,isgo,city,build,gzf);
				isgo[i] = false;
			}
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//城市数 道路数 改造数
	cin>>n>>m>>k;
    vector<vector<int> > city(n+1,vector<int>(n+1,-1));//第u个城市链接第v个城市的修复费用w 
    vector<vector<int> > build(n+1,vector<int>(n+1,-1));//第u次被修复的城市建筑第v个城市的道路费用w
    vector<bool> isgo(n+1,false);
    vector<int> gzf(n+1);
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		city[u][v] = w;
		city[v][u] = w;
	}
	for(int i = 1;i <= k;i++)
	{
		int c;
		cin>>c;
		gzf[i] = c;
		for(int j = 1;j <= n;j++)
		{
			int f;
			cin>>f;
			build[i][j] = f;
		}
	}
	dfs(1,0,0,1,isgo,city,build,gzf);
	cout<<mincost;
	return 0;
} 
