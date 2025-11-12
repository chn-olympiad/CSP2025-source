#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int to,w;
};
vector<node> e[1000005];
int kk[15][10005];
long long anss=0,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(node{v,w});
		e[v].push_back(node{u,w});
		anss+=w;
	}
	if(k==0)
	{	
		cout<<anss;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++) cin>>kk[i][j];
	}
	return 0;
}
