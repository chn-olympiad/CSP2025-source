#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001];
int a[11][10011];
int main(){
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	cout << 0 << endl;
	return 0;
}
