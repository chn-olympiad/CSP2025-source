#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1000001;
int u[N],v[N],w[N],a[11][10001];
int n,m,k,ans = 0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u[i];
		cin >> v[i];
		cin >> w[i];
	}
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			cin >> a[i][j];
		}
	}
	sort(w+1,w+m+1);
	for(int i = 1; i < n; i++){
		ans += w[i];
	}
	cout << ans;
	return 0;
} 
