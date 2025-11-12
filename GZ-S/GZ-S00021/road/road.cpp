//GZ-S00021  贵阳市第一中学  何傲杭 
#include <bits/stdc++.h>
using namespace std;
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
	}
	for(int i = 1; i <= k; i++){
		for(int i = 1; i <= n+1; i++){
			int t;	cin >> t;
			ans += t;
		}
	}
	if(ans % (2*(n+1)) == 0){
		cout << ans/2/(n+1);
	}else	cout << ans/2/(n+1)+1;
	return 0;
}
