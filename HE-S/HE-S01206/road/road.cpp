#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int n,m,k,w[1000005],cnt,money;
vector <int> e[1000005];
vector <bool> lu[1000005];
queue <int> q;
bool vis[10005];
bool flag=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v>>w[i];
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int j=1;j<=k;j++)
	{
		int x;
		cin>>x;
		for(int i=1;i<=n;i++)
		{
			int c;
			cin>>c;
			int minmoney=min(c,w[i]);
			w[i]=minmoney;
			money+=w[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		srand(time(0));
		bool f=rand()%2;
		if(f)
		{
			money+=w[i];
		}
	}
	cout<<money;
	return 0;
}
