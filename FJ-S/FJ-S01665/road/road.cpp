#include <bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005];
int a[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int c;
	for(int i = 1;i <= n;i++) cin >> u[i] >> v[i] >> w[i];
	cin >> c;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int sum = 0;
	for(int i = 1;i <= n;i++) sum += a[i];
	cout << sum << endl; 
	return 0;
}

