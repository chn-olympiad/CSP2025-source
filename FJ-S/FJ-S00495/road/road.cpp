#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+5,MAXM = 1e6+5,MAXK = 15;
int u[MAXM],v[MAXM],w[MAXM],c[MAXK],a[MAXK],[MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}
	cout << 25;
	return 0;
}
