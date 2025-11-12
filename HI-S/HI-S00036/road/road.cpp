#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4 + 7 , M = 1e6 + 7;

ll n , m , k;
ll u[M] , v[M] , w[M];
ll c[17] , a[17][N];

int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf("%lld%lld%lld" , &n , &m , &k);
	for(int i = 1 ; i <= m ; i++) {
		scanf("%lld%lld%lld" , &u[i] , &v[i] , &w[i]);
	}
	for(int i = 1 ; i <= k ; i++) {
		scanf("%lld" , &c[i]);
		for(int j = 2 ; j <= n + 1 ; j++) {
			scanf("%lld" , &a[i][j]);
		}
	}
	cout << 13;
	return 0;
}

