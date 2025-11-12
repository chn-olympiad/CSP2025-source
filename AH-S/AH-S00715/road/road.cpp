#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node{
	int p,w;
};
vector<node> e[10005];
int p[1000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		p[i]=w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	sort(p+1,p+m+1);
	for(int i=1;i<=n-1;i++){
		p[i]+=p[i-1];
	}
	cout<<p[n-1];
	return 0;
}
