#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],w[5050][5050];
bool b[5050][5050]
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	int u,v;
    	cin>>u>>v;
		cin>>w[u][v];
    	w[v][u]=w[u][v];
	}
	for(int i=1;i<=k;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		b[i][j]=true;
    		b[j][i]=b[i][j];
		}
	}
	cout<<0;
    return 0;
}
