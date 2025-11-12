#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1,u,v,w;i<=m;i++){
		cin >> u >> v >> w;
		ans+=w;
	}cout << ans;
	return 0;
} 
