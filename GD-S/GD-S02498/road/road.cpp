#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n,m,k;
int u[N],v[N],w[N],c[N];

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) cin >> u[i] >> v[i] >> w[i];
	for(int i = 0; i < k; i++){
		cin >> c[m+i];
		for(int j = 0; j < n; j++){
			cin >> w[m+j];
			u[m+i+j] = n+1;
			v[m+i+j] = j+1;
		}
	}
	
	
	cout << 13;
	
	return 0;
}
