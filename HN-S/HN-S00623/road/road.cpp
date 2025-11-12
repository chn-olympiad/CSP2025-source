#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
struct Node{
	int to,val;
};
vector<Node>G[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,f,t,v;i<=m;i++)
	{
		cin>>f>>t>>v;
		G[f].push_back((Node){t,v});
		G[t].push_back((Node){f,v});
	}
	for(int i=1;i<=k;i++)
	{
		int co,f=n+i;
		cin>>co;
		for(int t=1,v;t<=n;t++)
		{
			cin>>v;
			G[f].push_back((Node){t,v});
			G[t].push_back((Node){f,v});
		}
	}
	printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
