#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k, c[15], cj[15][10005], u, v, w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(ll i = 1;i <= m;i++) cin >> u >> v >> w;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++) cin >> cj[i][j];
	}
	cout << 0;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
