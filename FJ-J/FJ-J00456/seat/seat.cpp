#include <bits/stdc++.h>
using namespace std;
const int N = 250;
int w[N];
int g[N][N];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int len = n * m;
	for(int i = 1 ; i <= len ; i ++) cin >> w[i];
	int x = w[1];
	int k = 1;
	sort(w + 1 , w + len + 1 , cmp);
	for(int i = 1 ; i <= n ; i ++){
		if(i % 2 == 0){
			for(int j = m ; j >= 1 ; j --){
				g[i][j] = w[k ++];
			}
		}else{
			for(int j = 1 ; j <= m ; j ++){
				g[i][j] = w[k ++];
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			if(g[i][j] == x){
				cout << i << " " << j << '\n';
				return 0;
			}
		}
	}
	return 0;
}
