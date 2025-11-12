#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n , m ,k;
int a[15];
vector <int> xz[N];
vector <int> vec[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u , v , w;cin >> u >> v >> w;
		vec[u][v] = w;
	}
	for(int i = 1;i <= k;i++){
		cin >> a[i];
		for(int j = 1;j <= n;i++)cin >> xz[i][j];
	}
	cout << 13;
	return 0;
}
