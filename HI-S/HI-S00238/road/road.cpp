#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int dad[10020],cost[10020][10020];
int find(int x){
	if (dad[x]==x) return x;
	return find(dad[x]); 
}
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
    	dad[i]=i;
	}
    for (int i=1;i<=m;i++)
    {
    	int a,b;
    	cin>>a>>b>>cost[a][b];
    	cost[b][a]cost[a][b];
	}
    for (int i=1;i<=k;i++)
    {
    	cin>>cost[n+i][0];
    	for (int j=1;j<=n;j++)
    	{
    		cin>>cost[n+i][j];
    		if (cost[n+i][j]==0&&cost[n+i][0]==0) dad[n+i]=find(j);
    		cost[j][n+i]=cost[n+i][j];
		}
	}
	for (int a=1;a<=n;a++)
	{
		int ansa=1000000010,ansb=1000000010,ansc=1000000010;
		if (find(a)!=find(1))
		{
			for (int i=1;i<=n;i++)
			{
				if (find(i)==find(1)) ansb=min(ansb,cost[i][a]);
			}
			ansb+=ans;
			dad[find[a]]=find(1); 
		}
	}
	cout<<ans;
	return 0;
}

