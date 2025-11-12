#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[1000010],u[1000010],w[1000010];
int a[15][10010];
int c[15];
long long ans;
int main() {
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		cin >> u[i] >> v[i] >> w[i];
		ans += w[i]; 
	}
	for(int i = 1;i <= k;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	cout << ans;
	return 0;
}
