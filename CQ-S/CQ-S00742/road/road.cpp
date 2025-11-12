#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long w[1001000];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		long long u,v,x; 
		cin >> u >> v >> w[i];
	}
	for(int i = 1;i <= k;i++){
		int c;
		cin >> c;
		for(int j = 1;j <= n;j++){
			int x;
			cin >> x;
		}
	}
	sort(w + 1,w + 1 + m);
	for(int i = 1;i <= n - 1;i++){
		ans += w[i];
	}
	cout << ans;
	return 0;
}
