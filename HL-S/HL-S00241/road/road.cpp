#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 1e6+10;
int u[N],v[N],w[N];
int c[11],a[N];
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		cin >> u[i] >> v[i] >> w[i];
		sum += w[i];
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= m;j++){
			cin >> a[j];
		}
	}
	cout << sum;
	return 0;
}