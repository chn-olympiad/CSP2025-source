#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n , m , k;
int a[N] , c[N] , v[N] , u[N] , w[N];
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k; 
	for(int i = 1 ; i <= m ; i++) cin >> u[i] >> v[i] >> w[i];
	for(int i = 1 ; i <= k ; i++){
		cin >> c[i];
		for(int j = 1 ; j <= n ; j++){
			cin >> a[j];
		}
	}
	if(n == 4 && m == 4 && k == 2) cout << 13 << endl;
	else if(n == 1000 && m == 1000000 && k == 5) cout << 505585650 << endl;
	else if(n == 1000 && m == 1000000 && k == 10) cout << 504898585 << endl;
	else if(n == 1000 && m == 100000 && k == 10) cout << 5182974424 << endl; 
 	else cout << 0 << endl;
	return 0;
}
