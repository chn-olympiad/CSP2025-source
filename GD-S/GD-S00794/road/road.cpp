#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int INF = 0x3f3f3f;
#define ll long long 

int n , m , k;

vector<ll> G[N];
ll q[N][N] , t[15][N];

int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 , u , v , w ; i <= m ; i++){
		scanf("%lld%lld%lld" , &u , &v , &w);
		q[u][v] = w;
		q[v][u] = w;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1 ; i <= k ; i++){
		for(int j = 0 ; j <= n ; j++){
			scanf("%lld" , &t[i][j]) ;
		}
		for(int j = 1 ; j <= n ; j++){
			for(int p = j + 1 ; p <= n ; p++){
				if(t[i][j] + t[i][p] + t[i][0] < q[j][p]){
					q[j][p] = t[i][j] + t[i][p] + t[i][0];
				} 
			}
		}
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				if(k != i && k != j)q[i][j] = min(q[i][k] + q[k][j] , q[i][j]);
			}
		}
	}
	cout << q[1][n] << endl;
	return 0;
}

/*

Ren5Jie4Di4Ling5%
*/
