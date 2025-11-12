#include<bits/stdc++.h>
using namespace std;
int n , m  , k;
int a , b , c;
int mi = INT_MAX; 
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		cin >> a >> b >>c;
		mi = min(mi , c);
	}
	cout << c;
	return 0;
}
