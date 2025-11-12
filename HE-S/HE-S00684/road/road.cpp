#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		ans+=w;
	}
	cout << ans;
	return 0;
}
