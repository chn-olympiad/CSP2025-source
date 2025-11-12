#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int u[N], v[N], w[N], a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		for(int j = 1; j<= k; j++){
			cin >> a[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
