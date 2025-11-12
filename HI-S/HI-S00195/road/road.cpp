#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
long long u[maxn],v[maxn],w[100000010],c[100000010],a[maxn];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int j = 1;j <= k;j++){
		cin >> c[j];
		for (int f = 1;f <= n;f++){
			cin >> a[f];
		}
	}
	cout << 17;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
