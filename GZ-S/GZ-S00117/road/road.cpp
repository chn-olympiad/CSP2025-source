//GZ-S00117 贵阳市第十九中学 唐靖越
#include<bits/stdc++.h>
using namespace std ;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n , m , k , mn , a , b , c , d ;
	int w[1500000] , k1[1500000] , v[1500000] , u[1500000] , a1[1500000] , a2[1500000] , a3[1500000] , a4[1500000] ;
	cin >> n >> m >> k ;
	for(int i = 1 ; i <= m ; i++){
		cin >> u[i] >> v[i] >> w[i] ;
	}
	for(int i = 1 ; i <= k ; i++){
		cin >> k1[i] ;
		for(int j = 1 ; j <= n ; j++){
			cin >> a1[j] >> a2[j] >> a3[j] >> a4[j] ; 
		}
	}
	if(k == 0){
		for(int i = 1 ; i <= m ; i++){
			mn += w[i] ;
		}
		cout << mn ;
		return 0 ;
	}
	return 0 ;
}
