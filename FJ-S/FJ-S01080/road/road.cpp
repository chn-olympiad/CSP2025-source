#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n , m , k;
struct wtf{
	int u , v , w;
}st[maxn];
int cao[10][maxn];
bool cmp(wtf a , wtf b){
	return a.w > b.w;
}
int c[15];
int main(){
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i++){
		cin >> st[i].u >> st[i].v >> st[i].w;
	}
	sort (st + 1 , st + m + 1 , cmp);
	for (int i = 1 ; i <= k ; i++){
		cin >> c[i];
		for (int j = 1 ; j <= n ; j++) cin >> cao[i][j];
	}
	int ans = 0;
	
	return 0;
} 
