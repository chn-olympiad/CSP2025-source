#include<bits/stdc++.h>
using namespace std;
long long c[10010], a[11][10010], ans;
int n, m, k;
struct node{
	long long v, w;
};
vector<node> g[10010];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool f=1;
	cin>>n>>m>>k;
	while(m--){
		int u, v, w;
		cin>>u>>v>>w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		ans += w;
	}
	long long minn=0x3f3f3f3f;
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
			if(a[i][j] != 0) f = 0;
			minn=min(minn, a[i][j]);
			g[i].push_back({j, a[i][j]});
			g[j].push_back({i, a[i][j]});
		}
	}
	if(f){
		cout<<0<<endl;
		return 0;
	}
	cout<<ans/2+minn<<endl;
	return 0;
}