#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k,num = 0;
	cin >>n >>m>>k;
	int u[m+1],v[m+1],w[m+1],c[k+1],a[k+1][10001];
	for(int i = 1;i <= m;i++){
		cin >> u[i]>>v[i]>>w[i];
	}
	sort(w+1,w+n+1);
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= m*3/2;i++){
		num += w[i];
	}
	cout << num;
	return 0;
}
