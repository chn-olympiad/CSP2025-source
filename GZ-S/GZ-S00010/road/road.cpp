//GZ-S00010 付滨诚 贵阳市南明区双龙华麟学校
#include <bits/stdc++.h>
const int N=1e4+514;
using namespace std;
vector< pair<int,int> > g[N];
long long n,m,k,ans,maxn;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		maxn=max(maxn,w);
		ans+=w;
		g[u].push_back({v,w}),g[v].push_back({u,w});
	}
	cout<<ans-maxn;
	return 0;
} 
