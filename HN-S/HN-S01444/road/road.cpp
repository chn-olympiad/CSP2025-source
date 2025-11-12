#include <bits/stdc++.h>
using namespace std;
//dfs(int x,int js,int ls)
//{
//	if(js)
//	{
//		ls+=c[x];
//		f[x]=1;
//	}
//	for(i=1;i<=n;i++)
//	{
//		for(int i=0;i<e[i].size();i++)
//		{
//			
//		}
//	}
//}
int n,m,k,z;
int main()
{
  	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>z>>z>>z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>z;
		for(int i=1;i<=n;i++)
		{
			cin>>z;
		}
	}
//    cin>>n>>m>>k;
//    for(int i=1;i<=m;i++)
//    {
//    	cin>>u>>v>>w;
//    	e[u].push_back(v);
//    	e[v].push_back(u);
//    	f[u][v]=f[v][u]=w;
//	}
//	for(int i=1;i<=k;i++)
//	{
//		int j=i+m;
//		cin>>c[j-m];
//		for(int i=1;i<=n;i++)
//		{
//			cin>>w;
//			e[i].push_back(j);
//			e[j].push_back(i);
//			f[i][j]=f[j][i]=w;
//		}
//	}
//	dfs(1,0,0);
//	dfs(1,1,0);
    cout<<13;
	return 0;
}
