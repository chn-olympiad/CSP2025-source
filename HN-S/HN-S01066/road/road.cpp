#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=917891789178;
int n,m,k;
vector<int> r[10005],w[10005];
void add(int u,int v,int t)
{
	r[u].push_back(v);
	w[u].push_back(t);
}
int a[15][10005];
int c[15];
int ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,t;
		cin>>u>>v>>t;
		add(u,v,t);
		add(v,u,t);
		ans+=t;
	}
	for(int i=1;i<=k;i++)
	  for(int j=0;j<=n;j++)
	    cin>>a[i][j];
	
	cout<<ans;
	return 0;
}

