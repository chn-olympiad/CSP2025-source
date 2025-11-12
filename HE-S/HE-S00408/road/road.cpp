#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;
	cin >> n >> m >> k;
	int sum = 0;
	int x[20];
	int y[20];
	int z[20];
	cin >> t;
    for(int i = 1; i <= t; i++){
    	int n; 
    	cin >> n;
    	for(int i = 0; i < n; i++){
    		cin >> x[i] >> y[i] >> z[i];
    		int m = max(x[i] , x[i+1]);
    		sum+= M;
		}
		cout << sum << endl; 
	}
	for(int i = 0 ; i < t; i++){
		cout << sum[i];
	}
	return 0;
}
