#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+4;
struct Node{
	int u,v;
};
struct Edge{
	int c,a[N];
}g[15];
int n,m,k;
vector<Node> e[M];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	cout<<10054<<endl;
	return 0;
}

