#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;
int n,m,k,ans,c[N],val[N],a[15][N];
vector<PII>g[N];
inline void krus(){
	
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;val[i]=w;
		g[u].push_back({v,w});
		g[v].push_back({u,v});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
//	if(!k){
//		krus();
//		return 0;
//	}
	sort(val+1,val+1+n);
	for(int i=1;i<=m;i++)ans+=val[i];
	cout<<ans<<endl;
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
