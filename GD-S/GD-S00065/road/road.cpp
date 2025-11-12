#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> u(m),v(m),w(m);
	int sum=0;
	for(int i=0;i<m;++i){
		cin >> u[i] >> v[i] >> w[i];
		sum+=w[i];
	}
	vector<int> c(k);
	vector<vector<int>> a(k,vector<int> (n))
	for(int i=0;i<k;++i){
		cin >> c[i];
		for(int j=0;j<n;++j){
			cin >> a[i][j];
		}
	}
	cout << sum;
	return 0;
}
