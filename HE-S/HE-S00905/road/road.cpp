#include <bits/stdc++.h>
#define int long long
using namespace std;

int n , m , k , c[15] , cq[15][10010] , pq[10010][10010][2] , v[10010] , ans = 1e17;
vector <int> p[10010];
void dfs(int x , int cnt , int sum){
	if(cnt == n){ans = min(sum , ans);}
	for(int i = 0 ; i < p[x].size() ; i++){
		int y = p[x][i];
		if(v[y]) continue;
		v[y] = 1;
		dfs(y , cnt + 1 , sum + pq[x][y][1]);
		v[y] = 0;
	}
}

signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		int x , y , z;
		cin >> x >> y >> z;
		if(pq[x][y][0]) pq[x][y][1] = min(pq[x][y][1] , z);
		else p[x].push_back(y) , pq[x][y][1] = z , pq[x][y][0] = 1;
	}dfs(1 , 1 , 0);
	cout << ans;
	return 0;
}
 
